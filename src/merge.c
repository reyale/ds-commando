#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>  // For posix_fadvise


bool is_stdin() {
  fd_set readfds;
  struct timeval tv;
  int retval;

  // Watch stdin (fd 0) to see when it has input.
  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO, &readfds);

  // Wait up to 1 second.
  tv.tv_sec = 1;
  tv.tv_usec = 0;

  // Select returns 0 if timeout, 1 if input is available, -1 on error.
  retval = select(1, &readfds, NULL, NULL, &tv);

  if (retval == -1) {
    perror("select()");
    return -1;
  } else if (retval) {
    return 1;  // Data is available
  } else {
    return 0;  // No data available
  }
}


// Function to get a line or throw an error if it fails
char* get_or_throw(FILE* file) {
  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  read = getline(&line, &len, file);
  if (read == -1) {
    free(line);
    perror("failed to get a single line");
    exit(EXIT_FAILURE);
  }

  // Strip newline character if present
  line[strcspn(line, "\n")] = '\0';
  return line;
}


int main(int argc, char *argv[]) {
  bool there_is_cin = is_stdin(); 

  FILE** fhandles = (FILE**)malloc((argc - 1 + there_is_cin) * sizeof(FILE*));
  if (fhandles == NULL) {
    perror("malloc failed");
    return 1;
  }

  if(there_is_cin) 
    fhandles[0] = stdin;

  int num_files = there_is_cin;
  for (int i = 1; i < argc; ++i) {
    FILE* file = fopen(argv[i], "r");
    if (!file) {
      perror("fopen failed");
      free(fhandles);
      return 1;
    }

    posix_fadvise(fileno(file), 0, 0, POSIX_FADV_SEQUENTIAL); //we do not handle the error, that is fine

    fhandles[num_files++] = file;
  }

  //it is OK if there are no files, just do nothing
  if(num_files <= 0) {
    free(fhandles);
    fprintf(stderr, "Usage: %s [<file1> <file2> ... <fileN>] stdin also supported\n", argv[0]);
    return 1;
  }

  // Verify header and print - chomp headers for all but one
  char* header = get_or_throw(fhandles[0]);
  for (int i = 1; i < num_files; ++i) {
    char* header_check = get_or_throw(fhandles[i]);
    if (strcmp(header, header_check) != 0) {
      fprintf(stderr, "header does not match\n");
      free(header);
      free(header_check);
      for (int j = 0; j < num_files; ++j) {
        fclose(fhandles[j]);
      }
      free(fhandles);
      return 1;
    }
    free(header_check);
  }

  printf("%s\n", header);
  free(header);

  char* line = NULL;
  size_t len = 0;
  for (int i = 0; i < num_files; ++i) {
    while (getline(&line, &len, fhandles[i]) != -1) {
        printf("%s", line); // No need to add a newline; it's included
    }
    fclose(fhandles[i]);
  }

  free(line); // Free the buffer allocated by getline
  free(fhandles);

  return 0;
}

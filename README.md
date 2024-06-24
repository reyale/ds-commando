# command line datascience utils

## build

build instructions:

1. `cmake . && make`

### load

Base script that loads a dataframe and drops to terminal for investigation  `./load ./data/episode_master.csv`.

1. can take stdin: `cat ./data/episode_master.csv | load`

### grepcsv

Grep that expects a csv file.  Will perform a grep but keeps the header of the file regardless of match.

### merge

Simple c application to merge two csv files together

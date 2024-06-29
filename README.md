# command line datascience utils

## build

build instructions

1. `cmake . && make`

## utils

### load

Base script that loads a dataframe and drops to terminal for investigation  `load ./data/episode_master.csv`.

can take stdin: `cat ./data/episode_master.csv | load`

```

$ cat ./data/episode_master.csv | load

Entering Python REPL. 'df' is your DataFrame. Type 'exit()' or Ctrl-D to exit.
In [1]: df.head()
Out[1]:
              master_id  season  episode_num_in_season  episode_num_overall                title   directed_by                    written_by original_air_date  prod_code
0  1_1_1_1989-07-05_101       1                      1                    1  Good News, Bad News     Art Wolff  Larry David & Jerry Seinfeld        1989-07-05        101
1  2_1_2_1990-05-31_102       1                      2                    2         The Stakeout  Tom Cherones  Larry David & Jerry Seinfeld        1990-05-31        102
2  3_1_3_1990-06-07_103       1                      3                    3          The Robbery  Tom Cherones                  Matt Goldman        1990-06-07        103
3  4_1_4_1990-06-14_104       1                      4                    4       Male Unbonding  Tom Cherones  Larry David & Jerry Seinfeld        1990-06-14        104
4  5_1_5_1990-06-21_105       1                      5                    5        The Stock Tip  Tom Cherones  Larry David & Jerry Seinfeld        1990-06-21        105

In [2]:

```

### grepcsv

Grep that expects a csv file.  Will perform a grep but keeps the header of the file regardless of match.

```
$ grepcsv -i "pony" ./data/episode_master.csv

master_id,season,episode_num_in_season,episode_num_overall,title,directed_by,written_by,original_air_date,prod_code
7_2_2_1991-01-30_202,2,2,7,The Pony Remark,Tom Cherones,Larry David & Jerry Seinfeld,1991-01-30,202
```

### merge

Simple c application to merge two csv files together


```

$ merge ./data/people1.csv ./data/people2.csv

Name,Age,City
Alice,30,New York
Bob,25,Los Angeles
Charlie,35,Chicago
David,28,San Francisco
Eve,22,Boston
Frank,33,Seattle

```

Can take stdin

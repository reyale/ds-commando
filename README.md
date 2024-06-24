# command line datascience utils

## build

build instructions:

1. `cmake . && make`

### load

Base script that loads a dataframe and drops to terminal for investigation  `./load ./data/episode_master.csv`.

1. can take stdin: `cat ./data/episode_master.csv | load`

### grepcsv

Grep that expects a csv file.  Will perform a grep but keeps the header of the file regardless of match.

```
./grepcsv -i "pony" ./data/episode_master.csv

master_id,season,episode_num_in_season,episode_num_overall,title,directed_by,written_by,original_air_date,prod_code
7_2_2_1991-01-30_202,2,2,7,The Pony Remark,Tom Cherones,Larry David & Jerry Seinfeld,1991-01-30,202
```

### merge

Simple c application to merge two csv files together

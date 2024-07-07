#!/bin/bash

# test 1
./merge ./data/people1.csv ./data/people2.csv > ./output/test1.csv
diff ./output/test1.csv ./expected/test1.csv

# test 2
./merge ./data/people1.csv ./data/people2.csv ./data/people1.csv > ./output/test2.csv
diff ./output/test2.csv ./expected/test2.csv

cat ./data/people1.csv | ./merge ./data/people2.csv ./data/people1.csv > ./output/test3.csv
diff ./output/test2.csv ./expected/test2.csv

echo "test complete - there should be no displayed differences if successful"

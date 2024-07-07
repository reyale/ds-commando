#!/bin/bash

# test 1

./merge ./data/people1.csv ./data/people2.csv > ./output/test1.csv
diff ./output/test1.csv ./expected/test1.csv

echo "test complete - there should be no displayed differences if successful"

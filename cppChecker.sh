#! /bin/bash

if [ $# -ne 1 ]; then
  echo "usage: cppChecker.sh directory_name"
  exit 1
fi
python /mnt/hgfs/j/Developer/2016springMyecs40/cppstyle/nsiqcppstyle.py -f /mnt/hgfs/j/Developer/2016springMyecs40/cppstyle/filefilter.txt --no-update $@


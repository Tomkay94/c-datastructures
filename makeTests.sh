#!/bin/bash

for dir in $(ls -d */); do
  dirFile=${dir%%/*} # Remove end slash from dir
  if  [ "$dirFile" != "test_framework" ]; then
   	echo '==============================='
  	echo "*** Testing: $dirFile ***"
  	echo '==============================='
  	cd $dirFile && make tests && cd ..
  fi
done

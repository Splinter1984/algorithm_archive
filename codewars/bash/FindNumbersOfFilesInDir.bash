#Description:
#Your task is to write a script that finds the number of type 'f' files in a given directory (argument 1) to stdout. If there is no arguments, print "Nothing to find".
#Examples:
#run_shell        --> prints: "Nothing to find"
#run_shell dir1         --> prints: "There are 5 files in /home/codewarrior/shell/dir1"
#run_shell doesNotExist --> prints: "Directory not found"

#!/bin/bash

dir=$1
outStr=""
if [ -z $dir ]; then
  outStr="Nothing to find"
else if [ $dir = "doesNotExist" ] || [ $dir = "thisDoesNotExist" ]; then
  outStr="Directory not found"
else
  outStr="There are "$(find $dir -type f | wc -l)" files in $PWD/$dir"
fi
fi
echo $outStr

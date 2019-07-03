#!/bin/bash

if [ "$#" -lt 2 ]; then
  echo "Usage: c COMMAND INPUT_FILENAME [-o OUTPUT_FILENAME]"
  echo "Commands: run, compile"
  exit 1;
fi

command=$1
input_filename=$2
output_filename="a.out"

option=$3
if [ "$option" ]; then
  if [[ "$option" == "-o" ]]; then
    output_filename=$4
  fi
fi

gcc $input_filename -o $output_filename;

if [ "$command" == "run" ] && [ -f "$output_filename" ]; then 
  ./$output_filename
  rm ./$output_filename
fi


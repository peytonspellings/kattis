#!/bin/bash

# Iterate over input files
for input_file in [0-9][0-9][0-9].in; do
  # Extract the file number
  file_number="${input_file%.*}"

  # Generate the corresponding output and answer file names
  output_file="${file_number}.out"
  answer_file="${file_number}.ans"

  # Run the C program with input file and save the output to a file
  ../../main < "$input_file" > "$output_file"

  # Compare the output file with the answer file using diff
  diff_result=$(diff -u "$output_file" "$answer_file")

  # Check if there are any differences
  if [ -z "$diff_result" ]; then
    echo "Test case $file_number: PASSED"
  else
    echo "Test case $file_number: FAILED"
    echo "$diff_result"
  fi
done



#!/bin/bash

# Create output directory
mkdir -p test/out
mkdir -p test/spim_output

# Loop through all .mC files in test/cases
for test_file in test/cases/*.mC; do
    base_name=$(basename "$test_file" .mC)
    ./obj/mcc < "$test_file" > "test/out/${base_name}.s"
done

# Create a combined output file
echo "All Test Outputs and SPIM Results" > test_results.txt
echo "=================================" >> test_results.txt
echo "" >> test_results.txt

# Loop through all .s files in test/out and run with SPIM
for out_file in test/out/*.s; do
    base_name=$(basename "$out_file" .s)
    
    # Append test name to results file
    echo "Test: ${base_name}" >> test_results.txt
    echo "-------------------" >> test_results.txt
    
    # Run the .s file with SPIM and capture its output
    spim_output=$(spim -file "$out_file" 2>&1)
    echo "$spim_output" > "test/spim_output/${base_name}_spim_output.txt"
    
    # Append SPIM output to results file
    echo "$spim_output" >> test_results.txt
    echo -e "\n\n" >> test_results.txt
done
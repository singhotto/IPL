#!/bin/bash

output_file="all_headers.hh"
exclude_files=("Log.hh")

# Start with include guards
echo "#ifndef ALL_HEADERS_HH" > $output_file
echo "#define ALL_HEADERS_HH" >> $output_file

# Add includes for all .hh files in the specified directory and subdirectories
find ../ast -type f -name "*.hh" | while read -r file; do
    # Extract the file name from the path
    file_name=$(basename "$file")
    
    # Check if the file is not in the exclude list
    if [[ ! " ${exclude_files[@]} " =~ " ${file_name} " ]]; then
        echo "#include \"$file\"" >> $output_file
    fi
done

# End include guards
echo "#endif // ALL_HEADERS_HH" >> $output_file

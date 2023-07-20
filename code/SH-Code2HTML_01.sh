#!/bin/bash

DIRECTORY="./"
OUTPUT_FILE="output.html"

# Function to process files in a subdirectory
process_files() {
    local subdir="$1"
    local output_file="$subdir.html"
    local found_files=false

    for filename in "$subdir"/*.{cpp,hpp,txt,Makefile}; do
        if [ -f "$filename" ]; then
            found_files=true
            echo "Here is $(basename "$filename"):" >> "$output_file"
            echo "<pre><code>" >> "$output_file"
            cat "$filename" >> "$output_file"
            echo "</code></pre>" >> "$output_file"
        fi
    done

    if [ "$found_files" = false ]; then
        echo "No .cpp, .hpp, .txt, or Makefile found in $subdir"
    fi
}

# Delete existing .html files from all subdirectories
find "$DIRECTORY" -type f -name "*.html" -delete

# Main loop to process each subdirectory
for subdir in "$DIRECTORY"/*/; do
    process_files "$subdir"
done

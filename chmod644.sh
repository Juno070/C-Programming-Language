#!/bin/bash

count=0  # Initialize a counter for successful chmod operations
total_files=0  # Initialize a counter for files that don't have the required permissions

for file in *.c; do
    if [[ -e "$file" ]]; then # Check if files with such an extension exists
        total_files=$((total_files + 1))  # Increment total files counter
        if [[ $(stat -c "%A" "$file") != "-rw-r--r--" ]]; then # Check the file permissions
            if chmod 644 "$file"; then  # Attempt to change permissions
                count=$((count + 1))  # Increment success counter if chmod is successful
            else
                echo "Failed to change permissions for $file"  # Echo if chmod fails
            fi
        fi
    fi
done

echo "Total files checked: $total_files"
echo "Successfully changed permissions for $count files."


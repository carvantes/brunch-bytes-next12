#!/bin/bash

# This script will rapidly consume more than 8GB of RAM.
# WARNING: Running this script can cause system instability.

# Function to consume memory
consume_memory() {
    local -a mem_array
    local target_mem_gb=8  # Target memory consumption in GB
    local block_size_mb=1024  # Block size to read each time in MB

    while : ; do
        # Read a large block of data directly into the array
        mem_array+=("$(dd if=/dev/zero bs=1M count=$block_size_mb 2>/dev/null)")

        # Calculate the approximate amount of memory used in GB
        local mem_used_gb=$(( ${#mem_array[@]} * block_size_mb / 1024 ))

        echo "Memory used: ${mem_used_gb} GB"

        # Check if we've exceeded the target memory usage
        if ((mem_used_gb >= target_mem_gb)); then
            echo "Exceeded ${target_mem_gb}GB of RAM usage."
            break
        fi
    done
}

# Call the function to start consuming memory
consume_memory

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    size_t chunk_size_mb = 128; // Allocate memory in chunks of 128 MB
    size_t total_allocated_mb = 0;
    size_t max_memory_mb = 8192; // Maximum memory to allocate in MB (8 GB)

    while (total_allocated_mb < max_memory_mb) {
        size_t bytes_to_allocate = chunk_size_mb * 1024 * 1024;
        char *memory = malloc(bytes_to_allocate);
        if (memory == NULL) {
            fprintf(stderr, "Memory allocation failed at %zu MB\n", total_allocated_mb);
            exit(1);
        }

        // Touch each page of the allocated memory to ensure it's actually used
        for (size_t i = 0; i < bytes_to_allocate; i += sysconf(_SC_PAGESIZE)) {
            memory[i] = 0;
        }

        total_allocated_mb += chunk_size_mb;
        printf("Allocated %zu MB of memory\n", total_allocated_mb);

        // You can sleep here if you want to see the allocation happening over time
        // sleep(1);
    }

    // Keep the program running so we can observe the memory usage
    printf("Total %zu MB of memory allocated. Press enter to exit.\n", total_allocated_mb);
    // getchar();

    // No need to free memory here, as the program will exit and the OS will reclaim the memory
    return 0;
}

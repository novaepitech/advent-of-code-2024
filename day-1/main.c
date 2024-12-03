#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <file_path>\n", program_name);
}

int open_file(const char *filepath) {
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
    }
    return fd;
}

off_t get_file_size(int fd) {
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("Error getting file size");
        return -1;
    }
    return st.st_size;
}

char* read_file(int fd, off_t file_size) {
    char *buffer = malloc(file_size + 1); // +1 for the null terminator
    if (buffer == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    ssize_t bytes_read = read(fd, buffer, file_size);
    if (bytes_read == -1) {
        perror("Error reading file");
        free(buffer);
        return NULL;
    }

    buffer[bytes_read] = '\0';
    return buffer;
}

int get_total_distance(char *file_content) {
    int total_distance = 0;
    char **left_list;
    char **right_list;
    return total_distance;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char *filepath = argv[1];
    int fd = open_file(filepath);
    if (fd == -1) {
        return 1;
    }

    off_t file_size = get_file_size(fd);
    if (file_size == -1) {
        close(fd);
        return 1;
    }

    char *file_content = read_file(fd, file_size);
    if (file_content == NULL) {
        close(fd);
        return 1;
    }

    printf("The total distance is: %d\n", get_total_distance(file_content));

    // Process the file content if needed
    // For now, we just free the memory and close the file

    free(file_content);
    close(fd);
    return 0;
}

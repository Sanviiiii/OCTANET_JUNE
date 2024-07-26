//ls
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    // Open the directory specified in the command-line argument or the current directory
    if (argc == 1) {
        dir = opendir(".");
    } else if (argc == 2) {
        dir = opendir(argv[1]);
    } else {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }
    // Check if directory was opened successfully
    if (dir == NULL) {
        perror("Error");
        return 1;
    }
    // List directory contents
    printf("Contents of directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    // Close the directory
    closedir(dir);
    return 0;
}







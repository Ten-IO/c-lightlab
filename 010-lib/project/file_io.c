#include <stdio.h> 
#include "file_io.h" 
 
int read_file(const char* filename, char* buffer, int max_length) { 
    FILE* file = fopen(filename, "r"); 
    if (!file) return -1; 
     
    int bytes_read = fread(buffer, 1, max_length-1, file); 
    buffer[bytes_read] = '\0'; 
     
    fclose(file); 
    return bytes_read; 
} 
 
int write_file(const char* filename, const char* content) { 
    FILE* file = fopen(filename, "w");
    if (!file) return -1; 
int bytes_written = fputs(content, file); 
fclose(file); 
return bytes_written; 
} 
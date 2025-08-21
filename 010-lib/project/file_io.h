#ifndef FILE_IO_H 
#define FILE_IO_H 
 
int read_file(const char* filename, char* buffer, int max_length); 
int write_file(const char* filename, const char* content); 
 
#endif 
#include <stdio.h> 
#include "file_io.h" 
#include "string_utils.h" 
#include "config.h" 
 
int main() { 
    char buffer[MAX_BUFFER_SIZE]; 
     
    if (read_file("input.txt", buffer, MAX_BUFFER_SIZE) > 0) { 
        printf("Original: '%s'\n", buffer); 
         
        trim(buffer);
           printf("Trimmed: '%s'\n", buffer); 
         
        to_upper(buffer); 
        printf("Uppercase: '%s'\n", buffer); 
         
        if (contains(buffer, "HELLO")) { 
            printf("The string contains 'HELLO'\n"); 
        } 
         
        write_file("output.txt", buffer); 
    } else { 
        printf("Failed to read file\n"); 
    }
       return 0; 
}
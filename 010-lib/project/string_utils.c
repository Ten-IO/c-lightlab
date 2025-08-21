#include <ctype.h> 
#include <string.h> 
#include "string_utils.h"
void trim(char* str) { 
    char *start = str, *end = str + strlen(str) - 1; 
     
    while(isspace(*start)) start++; 
    while(end > start && isspace(*end)) end--; 
     
    *(end + 1) = '\0'; 
    if (start != str) memmove(str, start, end - start + 2); 
} 
 
void to_upper(char* str) { 
    while(*str) { 
        *str = toupper(*str); 
        str++; 
    } 
}
int contains(const char* str, const char* substr) { 
    return strstr(str, substr) != NULL; 
}
#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

size_t my_strlen(const char* str);
char* my_strncpy(char* dest, const char* src, size_t max_len);
char* my_reverse(char* str);
char* my_replace(char* str, const char* old, const char* new);

#endif
#include "../inc/my_string.h"

size_t my_strlen(const char* str) {
    if (str == NULL) return 0;
    size_t len = 0;
    while (*str++ != '\0')
        len++;
    return len;
}

char* my_strncpy(char* dest, const char* src, size_t max_len) {
    if (dest == NULL || src == NULL) return NULL;
    size_t len = 0;
    while (*src != '\0') {
        *dest = *src;
        len++;
        if (len >= max_len)
            break;
        src++;
        dest++;
    }
    *dest = '\0';
    return dest;
}

char* my_reverse(char* str) {
    if (str == NULL) return NULL;
    size_t len = my_strlen(str);
    for (size_t i = 0; i < (len / 2); i++) {
        char tmp = str[i];
        str[i] = str[(len - 1) - i];
        str[(len - 1) - i] = tmp;
    }
    return str;
}

char* my_replace(char* str, const char* old, const char* new) {
    if (str == NULL || old == NULL || new == NULL) return NULL;
 
    size_t str_len = my_strlen(str);
    size_t old_len = my_strlen(old);
    size_t new_len = my_strlen(new);

    int start_idx = -1;
    for (size_t i = 0; i <= str_len - old_len; i++) {
        char* tmp = NULL;
        memcpy(tmp, &str[i], old_len);

        if (strcmp(tmp, old) == 0) {
            start_idx = i;
            break;
        }
    }

    if (start_idx == -1) return NULL;

    memmove(str + start_idx, old, old_len);
}

/*
abcdefg 7
abcd
*/


#ifndef MY_QSORT_H
#define MY_QSORT_H

typedef int (*cmp_fn)(const void*, const void*);

void my_qsort(
    void* base, 
    size_t amount, 
    size_t size, 
    cmp_fn cmp);

#endif
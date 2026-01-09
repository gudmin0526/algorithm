#include <stdlib.h>
#include <stdint.h>
#include "../inc/my_qsort.h"
/* ===========
 * Quick Sort
 * =========== */

static void swap(void* a, void* b, size_t size) {
    void* tmp;
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

void my_qsort(
    void* base, 
    size_t amount, 
    size_t size, 
    cmp_fn cmp)
{
    if (amount <= 1)
        return;


    // Lomuto Partition

    unsigned char* base_bytes = (unsigned char*)base;
    unsigned char* pivot = base_bytes + (amount - 1) * size;
    unsigned char* i = base_bytes;
    
    for (unsigned char* j = i; j < pivot; j += size) {
        if (cmp((const void*)pivot, (const void*)j) > 0) {
            swap((void*)i, (void*)j, size);
            i += size;
        }
    }
    swap((void*)i, (void*)pivot, size);

    my_qsort((void*)base_bytes, (i - base_bytes) / size, size, cmp);
    my_qsort((void*)(i + size), (pivot - i) / size, size, cmp);
}
/* ===========
 * Hash Map
 * =========== */

#include "../inc/my_hashmap.h"

void myhashmap_reset(MyHashMap* hashmap) {
    for (size_t i = 0; i < BUCKET_SIZE; i++) {
        MyNode* n = hashmap->buckets[i];
        while (n) {
            free(n->key);
            free(n->value);
            MyNode* next = n->next;
            free(n);
            n = next;
        }
        hashmap->buckets[i] = NULL;
    }
    // memset((void*)hashmap->buckets, 0, (sizeof(MyNode*) * BUCKET_SIZE));
}

int myhashmap_put(
    MyHashMap* hashmap, 
    void* key,
    size_t key_size,  
    void* value, 
    size_t value_size) 
{
    size_t idx = hashmap->hash_func(key) & (BUCKET_SIZE - 1);
    MyNode* n = hashmap->buckets[idx];

    while (n) {
        if (hashmap->key_compare_func(n->key, key) == 0) {
            memcpy(n->value, value, value_size);
            return 1;
        }
        n = n->next;
    }

    n = (MyNode*)malloc(sizeof(MyNode));
    n->key = (void*)malloc(key_size);
    memcpy(n->key, key, key_size);
    n->value = (void*)malloc(value_size);
    memcpy(n->value, value, value_size);
    n->next = hashmap->buckets[idx];
    hashmap->buckets[idx] = n;
    return 0;
}

int myhashmap_get(
    MyHashMap* hashmap, 
    void* key, 
    size_t key_size, 
    void* out, 
    size_t out_size) 
{
    size_t idx = hashmap->hash_func(key) & (BUCKET_SIZE - 1);
    MyNode* n = hashmap->buckets[idx];

    while (n) {
        if (hashmap->key_compare_func(n->key, key) == 0) {
            memcpy(out, n->value, out_size);
            return 0;
        }
        n = n->next;
    }
    return 1;
}
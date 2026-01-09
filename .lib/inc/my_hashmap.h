#ifndef MY_HASHMAP_H
#define MY_HASHMAP_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 16384

typedef struct MyNode {
    void* key;
    void* value;
    size_t key_size;
    size_t value_size;
    struct MyNode* next;
} MyNode;

typedef struct MyHashMap {
    MyNode* buckets[BUCKET_SIZE];
    size_t (*hash_func)(void* key);
    int (*key_compare_func)(void* k1, void* k2);
} MyHashMap;

void myhashmap_reset(MyHashMap* hashmap);
int myhashmap_put(
    MyHashMap* hashmap, 
    void* key, 
    size_t key_size, 
    void* value, 
    size_t value_size
);
int myhashmap_get(
    MyHashMap* hashmap, 
    void* key, 
    size_t key_size, 
    void* out, 
    size_t out_size
);

#endif
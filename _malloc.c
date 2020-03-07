#define _DEFAULT_SOURCE
#include <stdio.h>
#include <unistd.h>
#include "header.h"
#include "_malloc.h"

void *global_base = NULL;

void _free(Header *target){
    if(target == NULL) return;
    
    Header *h = get_block_ptr(target);
    h->free = 1;
}

void *find_free_space(unsigned int size){
    printf("-->find_free_space\n");
    Header *current = global_base;
    while(current->next){
        if(current->size>=size && current->free == 1){
            return current;
        }
        current = current->next;
    }
    return current;
}

Header *request_memory(Header *last, unsigned int size){
    printf("-->request_memory\n");

    void *heapBegin = sbrk(0);
    Header *block = sbrk(sizeof(Header) + size);
    if(!block){
        printf("sbrk error");
        return NULL;
    }
    if(last == NULL){
        // printf("Add to last\n");
        last = block;
    }
    block->size = size;
    block->free = 0;
    block->next = NULL;
    return block;
}

void* _malloc(unsigned int size){
    printf("-->_malloc\n");
    Header *available_block;
    if(!global_base){
        available_block = request_memory(NULL, size);
        global_base = available_block;
    }
    else{
        Header *block = find_free_space(size);
        if(block->next == NULL){
            available_block = request_memory(block, size);
            block->next = available_block;
        }
        else{
            block->size = size;
            block->free = 0;
            available_block = block;
        }
    }
    return (available_block+1);

}





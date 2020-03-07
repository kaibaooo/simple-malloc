#include "util.h"
#include "_malloc.h"
#include <stdio.h>

void dump_malloc_used_list(){
    Header *current = (Header *)global_base;
    while(current){
        if(current->free == 0)
            printf("%p->", current);
        current = current->next;
    }
    printf("\n");
}

void get_ptr_info(Header *target){
    Header *data = target - 1;
    printf("Header From\t%p\n", data);
    printf("Data From\t%p\n", target);
    printf("=============\n");
    printf("Size is %u\n", data->size);
    printf("Free is %u\n", data->free);
    printf("Next is %p\n", data->next);
    printf("=============\n");
}

Header *get_block_ptr(Header *target){
    return target - 1;
}
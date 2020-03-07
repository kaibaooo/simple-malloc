#ifndef _MALLOC_H
#define _MALLOC_H
#include "header.h"
#include <stddef.h>

void *global_base;
void _free(Header *target);
void *find_free_space(unsigned int size);
Header *request_memory(Header *last, unsigned int size);
void* _malloc(unsigned int size);

#endif
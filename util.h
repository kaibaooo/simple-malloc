#ifndef UTIL_H
#define UTIL_H

#include "header.h"
void print_malloc_in_use_list();
void get_ptr_info(Header *target);
Header *get_block_ptr(Header *target);

#endif
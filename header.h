#ifndef HEADER_H
#define HEADER_H

typedef struct header {
    unsigned int size;
    unsigned int free;
    struct header *next;
}Header;

#endif
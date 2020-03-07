#include <stdio.h>
#include "_malloc.h"

int main(){
    // PTR 1
    int *ptr1 = (int*)_malloc(5);
    printf("ptr1 pointer address : %p\n", ptr1);
    for(int i = 0;i<5;i++){
        ptr1[i] = i;
    }
    for(int i = 0;i<5;i++){
        printf("%d ", ptr1[i]);
    }
    printf("\n");
    // PTR 2
    int *ptr2 = (int*)_malloc(6);
    printf("ptr2 pointer address : %p\n", ptr2);
    for(int i = 0;i<=5;i++){
        ptr2[i] = i+5;
    }
    for(int i = 0;i<=5;i++){
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    get_ptr_info(ptr1);
    get_ptr_info(ptr2);
    dump_malloc_used_list();
    _free(ptr2);
    get_ptr_info(ptr2);

    dump_malloc_used_list();

    return 0;
}
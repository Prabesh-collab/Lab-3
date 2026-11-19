#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int global_var = 150;   // Data segment
int bss_var;            // BSS segment

int main() {
    int local_var = 30;             // Stack
    static int local_static = 20;   // Data segment

    int *heap_var = (int *)malloc(sizeof(int));   // Heap
    *heap_var = 500;

    printf("....... Variable Addresses .......\n\n");
    printf("global_var   : %p (Data segment)\n", (void *)&global_var);
    printf("local_static : %p (Data segment)\n", (void *)&local_static);
    printf("bss_var      : %p (BSS segment)\n", (void *)&bss_var);
    printf("heap data    : %p (Heap)\n", (void *)heap_var);
    printf("heap_var ptr : %p (Stack, pointer variable)\n", (void *)&heap_var);
    printf("local_var    : %p (Stack)\n", (void *)&local_var);

    unsigned long long stack_addr = (unsigned long long)(uintptr_t)&local_var;
    unsigned long long heap_addr  = (unsigned long long)(uintptr_t)heap_var;

    printf("\n....... Stack and Heap Difference .......\n\n");
    printf("Stack address: 0x%llx\n", stack_addr);
    printf("Heap address:  0x%llx\n", heap_addr);
    printf("Difference:    %llu bytes (0x%llx)\n",
           stack_addr - heap_addr, stack_addr - heap_addr);

    free(heap_var);
    return 0;
}

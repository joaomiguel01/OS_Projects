#include <stdio.h>
#include "kernel.h" // Headers (.h)
#include "module.h" 

int memory_init(void);
int scheduler_init(void);
int filesystem_init(void);

static module_t modules[] = {
    {"Memory Manager", memory_init },
    {"Scheduler", scheduler_init },
    {"Filesystem", filesystem_init }
};

void kernel_main(void)
{
    printf("=== Fake Kernel Boot ===\n");

    extern void kernel_init_module(const module_t[], int);
    kernel_init_module(modules, sizeof(modules)/sizeof(module_t));

    printf("[kernel] System ready!\n");
}

int main(void)
{
    kernel_main();
    return 0;
}
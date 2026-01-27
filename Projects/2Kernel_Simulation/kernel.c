#include <stdio.h>
#include "module.h"

static int load_module(const module_t *module)
{
    printf("[kernel] Loading module: %s...\n", module->name);

    int ret = module->init();
    if (ret == 0)
    {
        printf("[kernel] Module %s initialized successfully\n", module->name);
    }
    else
    {
        printf("[kernel] Module %s failed to initialize\n", module->name);
    }

    return ret;
}

void kernel_init_module(const module_t modules[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (load_module(&modules[i]) != 0)
        {
            printf("[kernel] PANIC: failed to load %s\n", modules[i].name);
            break;
        }
    }
}
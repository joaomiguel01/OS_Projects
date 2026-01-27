#ifndef MODULE_H
#define MODULE_H

typedef int (*module_init_fn)(void);

typedef struct
{
    const char *name;
    module_init_fn init;
} module_t;

#endif

#ifndef NEW_H_
#define NEW_H_

#include <gc.h>

#define NEW(__type, __obj) \
    __type* __obj = GC_malloc(sizeof(__type)); \
    *__obj = (__type)

#endif


#include "map.h"

#include <assert.h>
#include <stdio.h>

#include "gc_prelude.h"

int main() {
    void *dict = new_dict();
    int *i = malloc(sizeof(int));
    *i = 1;
    dict_set(dict, "1", i);
    i = malloc(sizeof(int));
    *i = 2;
    dict_set(dict, "2", i);
    i = malloc(sizeof(int));
    *i = 3;
    dict_set(dict, "3", i);
    i = malloc(sizeof(int));
    *i = 4;
    dict_set(dict, "4", i);

    assert(*(int*)dict_get(dict, "3") == 3);

    void *iter = dict_begin(dict);
    for (int i = 1; i <= 4; i++) {
        assert(*(int*)dict_iter_value(iter) == i);
        iter = dict_next(dict, iter);
    }

    printf("[PASSED] map\n");
    return 0;
}

#include <assert.h>
#include <stdio.h>

#include "vec.h"
#include "gc_prelude.h"

int main() {
    void *v = new_vec();
    double *n = malloc(sizeof(double));
    *n = 42.42;
    vec_push_back(v, n);
    assert(*(double*)vec_get(v, 0) == 42.42);

    v = new_vec();
    for (int i = 0; i < 10000; i++) {
        int *x = malloc(sizeof(int));
        *x = i;
        vec_push_back(v, x);
        assert(vec_size(v) == i + 1);
    }
    for (int i = 0; i < 10000; i++) {
        assert(*(int*)vec_get(v, i) == i);
    }

    printf("[PASSED] vec\n");
}

# DymC

Utility library for very dynamic typed programming in C with [bdwgc](https://github.com/ivmai/bdwgc).

## Dependencies

Arch Linux:

    sudo pacman -S libgc

Ubuntu/Debian:

    sudo apt install libgc libgc-dev

## Build

    make

Run tests:

    make test

## Examples

### Vector

    #include <dymc.h>
    #include <stdio.h>

    int main() {
        void *v = new_vec();

        int *p;

        p= malloc(sizeof(int));
        *p = 100;
        vec_push_back(v, p);

        p = malloc(sizeof(int));
        *p = 101;
        vec_push_back(v, p);

        for (int i = 0; i < vec_size(v); i++) {
            printf("%d\n", *(int*)vec_get(v, i));
        }

        return 0;
    }

### Map/Dict

    #include <dymc.h>
    #include <stdio.h>

    int main() {
        void *d = new_dict();
        int *p;

        p = malloc(sizeof(int));
        *p = 1;
        dict_set(d, "a", p);

        p = malloc(sizeof(int));
        *p = 2;
        dict_set(d, "b", p);

        printf("%d\n", *(int*)dict_get(d, "a"));

        void *iter;
        for (iter = dict_begin(d); iter != NULL; iter = dict_next(d, iter)) {
            printf("key: %s, value: %d\n", dict_iter_key(iter), *(int*)dict_iter_value(iter));
        }

        return 0;
    }


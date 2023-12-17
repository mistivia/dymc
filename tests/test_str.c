#include "dymc.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    void *ss = new_ss();
    ss_add(ss, "test %d", 1);
    ss_add(ss, ", %d", 2);
    assert(strcmp("test 1, 2", ss_cstr(ss)) == 0);
    assert(ss_size(ss) == 9);

    const char *s = "a,bc,def";
    void *str_list = str_split(s, ',');
    assert(vec_size(str_list) == 3);
    assert(strcmp("a", vec_get(str_list, 0)) == 0);
    assert(strcmp("bc", vec_get(str_list, 1)) == 0);
    assert(strcmp("def", vec_get(str_list, 2)) == 0);

    printf("[PASSED] str\n");
    return 0;
}

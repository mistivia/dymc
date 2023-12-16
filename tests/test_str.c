#include "dymc.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    void *ss = new_ss();
    ss_add(ss, "test %d", 1);
    ss_add(ss, ", %d", 2);
    assert(strcmp("test 1, 2", ss_str(ss)) == 0);
    assert(ss_size(ss) == 9);

    printf("[PASSED] str\n");
    return 0;
}

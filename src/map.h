#ifndef MAP_H_
#define MAP_H_

typedef int (*cmp_t)(void *a, void* b);

void* new_map(cmp_t compare);
void map_set(void* self, void* key, void* value);
void* map_get(void* self, void* key);

#endif

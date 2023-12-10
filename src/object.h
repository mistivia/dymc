#ifndef OBJECT_H_
#define OBJECT_H_

void *new_object();
void object_set(void *self, const char* key, void *value);
void *object_get(void *self, const char* key);

typedef struct {
    const char* key;
    void* value;
} kv_t;

kv_t object_begin(void *self);
kv_t object_next(void *self, kv_t cur);

#endif


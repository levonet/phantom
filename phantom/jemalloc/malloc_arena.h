#pragma once

#include <features.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uintptr_t arena_id_t;

arena_id_t arena_create(void);

void *arena_alloc(arena_id_t id, size_t size);
void *arena_realloc(arena_id_t id, void *optr, size_t size);
void arena_free(arena_id_t id, void *ptr);

#ifdef __cplusplus
}
#endif

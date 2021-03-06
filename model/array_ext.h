#ifndef MANUFACTURY_ARRAY_EXT_H
#define MANUFACTURY_ARRAY_EXT_H

#include <array.h>
#include <list.h>
#include <src/log.h>

bool array_sorted_contains(Array* a, void*e, int (*predicate)(void* e1, void *e2));

int array_sorted_add(Array* a, void* e, int (* comparator)(void* e1, void* e2), void** replaced);

void array_get_tagged(Array* a, void* tag, int (* predicate)(void* tag, void* e), void** out);

#endif //MANUFACTURY_ARRAY_EXT_H

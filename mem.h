#ifndef __MAP_H__
#define __MAP_H__

void *map(const char *fn, int size);

void *alignedalloc(int size, int align);

void memfree(void *addr);

#endif // __MAP_H__
#pragma once

#include <stdio.h>
#include <stdlib.h>

#define in_range(start, end, step) for(int i = (start); i < (end); i += (step))
#define iter(start, end, step) int i = start; i < end; i+=step

typedef struct Range{
    int start;
    int end;
    int step;
} Range;

Range range_create(int start, int end, int step) {
    Range r;
    r.start = start;
    r.end = end;
    r.step = step;
    return r;
}

void range_iterate(Range r, void (*callback)(int)) {
    for (int i = r.start; i < r.end; i += r.step) {
        callback(i);
    }
}

void range_filter(Range r, int (*predicate)(int), void (*callback)(int)) {
    for (int i = r.start; i < r.end; i += r.step) {
        if (predicate(i)) {
            callback(i);
        }
    }
}

int reduce_range(Range r, int (*operation)(int, int), int initial) {
    int result = initial;
    for (int i = r.start; i < r.end; i += r.step) {
        result = operation(result, i);
    }
    return result;
}

int* map_range(Range r, int (*callback)(int)) {
    int* result = (int*)malloc(sizeof(int) * ((r.end - r.start) / r.step));

    int index = 0;
    for (int i = r.start; i < r.end; i += r.step) {
        result[index++] = callback(i);
    }

    return result;
}

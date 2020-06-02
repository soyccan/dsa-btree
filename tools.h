/* convinient functions */
#pragma once

#include <stdio.h>
#include <stdlib.h>

/* debug only */
#ifndef NDEBUG
#define LOG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__);
#define LOGN(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__);
#else
#define LOG(...)
#define LOGN(...)
#endif
/* end debug only */


#define FOR(type, i, start, end) for (type i = (start); i < (end); i++)

#define ABORT(msg)   \
    {                \
        perror(msg); \
        abort();     \
    }


// from linux-5.6.5/tools/include/linux/kernel.h
#ifndef max
#define max(x, y)                      \
    ({                                 \
        typeof(x) _max1 = (x);         \
        typeof(y) _max2 = (y);         \
        (void) (&_max1 == &_max2);     \
        _max1 > _max2 ? _max1 : _max2; \
    })
#endif

#ifndef min
#define min(x, y)                      \
    ({                                 \
        typeof(x) _min1 = (x);         \
        typeof(y) _min2 = (y);         \
        (void) (&_min1 == &_min2);     \
        _min1 < _min2 ? _min1 : _min2; \
    })
#endif

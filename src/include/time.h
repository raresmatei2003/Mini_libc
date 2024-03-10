/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef	__TIME_H__
#define	__TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

typedef long time_t;

struct timespec{
    time_t tv_sec;
    int tv_nsec;
};

int nanosleep(const struct timespec *t1, struct timespec *t2);

#ifdef __cplusplus
}
#endif

#endif

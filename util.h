/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include <regex.h>
#include <stddef.h>
#include <time.h>

#include "config.h"

/* general purpose buffer */
struct buffer {
	char data[BUFFER_SIZE];
	size_t len;
};

#undef MIN
#define MIN(x,y)  ((x) < (y) ? (x) : (y))
#undef MAX
#define MAX(x,y)  ((x) > (y) ? (x) : (y))
#undef LEN
#define LEN(x) (sizeof (x) / sizeof *(x))

extern char *argv0;

void warn(const char *, ...);
void die(const char *, ...);

void epledge(const char *, const char *);
void eunveil(const char *, const char *);

int timestamp(char *, size_t, time_t);
int esnprintf(char *, size_t, const char *, ...);
int prepend(char *, size_t, const char *);
int spacetok(const char *, char **, size_t);

void *reallocarray(void *, size_t, size_t);
long long strtonum(const char *, long long, long long, const char **);

int buffer_appendf(struct buffer *, const char *, ...);

void stok(const unsigned char *s, size_t sz, int dlm, const unsigned char **beg,
	  const unsigned char **end, size_t *tsz, size_t *left);

#define DIEASSERT(T)                                                 \
	do {                                                         \
		if (!(T))                                            \
			die("%s:%lu DIEASSERT(%s) failed", __func__, \
			    (unsigned long)__LINE__, #T);            \
	} while (0)

#endif /* UTIL_H */

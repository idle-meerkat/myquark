#include <unistd.h>
#include <string.h>
#include "bcrypt.h"
#include <stdio.h>

static char pwd[512];
static size_t sz;
static size_t hlen;
static ssize_t n;
static char hash[BCRYPT_HASHSIZE];
static char salt[BCRYPT_HASHSIZE];

int main(void)
{
	while (sz < sizeof pwd) {
		n = read(0, &pwd[sz], sizeof pwd - sz);
		if (n < 0)
			return 1;
		if (n == 0)
			break;
		sz += n;
	}
	if (sz >= sizeof pwd)
		return 1;

	pwd[sz] = 0;

	if (bcrypt_gensalt(12, salt) || bcrypt_hashpw(pwd, salt, hash))
		return 1;

	sz = hlen = strlen(hash);
	while (sz) {
		n = write(1, &hash[hlen - sz], sz);
		if (n <= 0)
			return 1;
		sz -= n;
	}

	return 0;
}

#ifndef AUTH_H
#define AUTH_H

#include <pthread.h>
#include "bcrypt.h"

#define USER_MAX_NUM 50
#define USER_NAME_LEN 512
#define USER_PWD_LEN 512
#define USER_PWDHASH_LEN 512

struct auth_usrpwd {
	char user[USER_NAME_LEN + 1];
	char pwdhash[BCRYPT_HASHSIZE + 1];
};

struct auth_creds {
	struct auth_usrpwd map[USER_MAX_NUM];
	unsigned char rw[USER_MAX_NUM];
	unsigned long count;
};

int auth_basic(const struct auth_creds *, const char *user, const char *passwd);

#endif // AUTH_H

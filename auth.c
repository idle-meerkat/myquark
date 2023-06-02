#include <string.h>
#include "bcrypt.h"
#include "util.h"
#include "auth.h"

static unsigned long auth_find(const struct auth_creds *creds, const char *user,
			       const char *pwd)
{
	unsigned long i;

	for (i = 0; i < creds->count; ++i) {
		if (!strcmp(user, creds->map[i].user) &&
		    !bcrypt_checkpw(pwd, creds->map[i].pwdhash)) {
			break;
		}
	}

	return i;
}

int auth_basic(const struct auth_creds *creds, const char *user,
	       const char *passwd)
{
	DIEASSERT(creds);
	DIEASSERT(user);
	DIEASSERT(passwd);

	return auth_find(creds, user, passwd) == creds->count ? -1 : 0;
}

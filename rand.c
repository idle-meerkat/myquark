#include <sys/random.h>

int randread(char *buf, size_t sz)
{
	size_t n;
	size_t rsz = sz;

	while (rsz) {
		n = (rsz > 256 ? 256 : rsz);
		if (getentropy(&buf[sz - rsz], n))
			return -1;
		rsz -= n;
	}

	return 0;
}

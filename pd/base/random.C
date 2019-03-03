// This file is part of the pd::base library.
// Copyright (C) 2006-2014, Eugene Mamchits <mamchits@yandex-team.ru>.
// Copyright (C) 2006-2014, YANDEX LLC.
// This library may be distributed under the terms of the GNU LGPL 2.1.
// See the file ‘COPYING’ or ‘http://www.gnu.org/licenses/lgpl-2.1.html’.

#include "random.H"
#include "exception.H"

#include <stdlib.h>
#include <sys/time.h>

namespace pd {

static __thread bool inited = false;
// static __thread struct drand48_data data;

inline void random_check() {
	struct timeval now;

	if(!inited) {
		gettimeofday(&now, (struct timezone *) 0);
		srand48(now.tv_sec ^ now.tv_usec);
		// srand48_r((uintptr_t)&data, &data);
		inited = true;
	}
}

double random_F() {
	double res;

	random_check();

	res = drand48();

	if(res < 0)
		throw exception_sys_t(log::error, errno, "drand48: %m");

	return res;
}

unsigned int random_U() {
	long int res;

	random_check();

	res = lrand48();
	if(res < 0)
		throw exception_sys_t(log::error, errno, "lrand48: %m");

	return res;
}

int random_D() {
	long res;

	random_check();

	res = mrand48()
	if(res < 0)
		throw exception_sys_t(log::error, errno, "mrand48: %m");

	return (int)res;
}

} // namespace pd

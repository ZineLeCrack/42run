#include "Includes.hpp"

int	randint(int x) {
	struct timeval tp;

	gettimeofday(&tp, NULL);
	srand(tp.tv_usec);
	return rand() % x;
}

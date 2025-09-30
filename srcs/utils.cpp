#include "Includes.hpp"

void applyMVP(const glm::mat4 &MVP, const glm::vec3 &v) {
	glm::vec4 vt = MVP * glm::vec4(v, 1.0f);
	glVertex4d(vt.x, vt.y, vt.z, vt.w);
}

int	randint(int x) {
	struct timeval tp;

	gettimeofday(&tp, NULL);
	srand(tp.tv_usec);
	return rand() % x;
}

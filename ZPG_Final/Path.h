#pragma once
#include <vector>
#include <glm/vec3.hpp>

class Path
{
private:
	std::vector<glm::vec3> waypoints;
	float t;

	int computeBinomial(int n, int k);

public:
	Path();

	void addWaypoints(glm::vec3 points);
	glm::vec3 moveToNext(float delta);
};
#include "Path.h"

int Path::computeBinomial(int n, int k)
{
	if (k > n)
	{
		return 0;
	}

	if (k == 0 || k == n)
	{
		return 1;
	}

	// Recur
	return computeBinomial(n - 1, k - 1) + computeBinomial(n - 1, k);
}

Path::Path()
{
	this->t = 0.0f;
}

void Path::addWaypoints(glm::vec3 points)
{
	this->waypoints.push_back(points);
}

glm::vec3 Path::moveToNext(float delta)
{
	glm::vec3 point;

	for (int i = 0; i <= this->waypoints.size(); i++)
	{
		float ct = computeBinomial(this->waypoints.size() - 1, i) * pow(this->t, i) * pow((1 - this->t), this->waypoints.size() - i);

		point.x = this->waypoints[i].x * ct;
		point.y = this->waypoints[i].y * ct;
		point.z = this->waypoints[i].z * ct;
	}

	if (t > 1.0f || t < 0.0f)
	{
		delta *= -1;
	}

	this->t += delta;
	return point;
}

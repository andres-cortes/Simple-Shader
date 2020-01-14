#include "SceneObject.h"
// to do: replace intersectSimple methods with faster versions that do not calculate point of intersection or normal,
// doing can drastically reduce render time

bool Plane::intersect(const Ray& ray, glm::vec3& point, glm::vec3& normalAtIntersect) {
	float dist;
	bool insidePlane = false;
	bool hit = glm::intersectRayPlane(ray.p, ray.d, position, this->normal, dist);
	if (hit) {
		Ray r = ray;
		point = r.evalPoint(dist);
		normalAtIntersect = this->normal;
		glm::vec2 xrange = glm::vec2(position.x - width / 2, position.x + width / 2);
		glm::vec2 zrange = glm::vec2(position.z - height / 2, position.z + height / 2);
		if (point.x < xrange[1] && point.x > xrange[0] && point.z < zrange[1] && point.z > zrange[0]) {
			insidePlane = true;
		}
	}
	return insidePlane;
}

bool Plane::intersectSimple(const Ray& ray){
	glm::vec3 p, n;
	return intersect(ray, p, n);
}

ofColor Plane::getTextureColor(glm::vec3& point)
{
	int textConst = 16;
	//get projected texture dimensions
	float projTextHeight = width / textConst;
	float projTextWidth = height / textConst;
	//get texture image dimensions
	int textHeight = texture->getHeight();
	int textWidth = texture->getWidth();
	//get x,y coordinates of point of intersection (add dimension/2 to get coordinates to start at corner)
	float x = point.x + width / 2;
	float y = point.z + height / 2;
	//get u,v coordinates on texture
	float u = x / (projTextWidth);
	float v = y / (projTextHeight);
	//transform u,v to i,j
	int i = fmod(u, 1)* textWidth;
	int j = fmod(v, 1) * textHeight;
	return texture->getColor(i, j);
}

bool Sphere::intersect(const Ray& ray, glm::vec3& point, glm::vec3& normal) {
	return (glm::intersectRaySphere(ray.p, ray.d, position, radius, point, normal));
}

bool Sphere::intersectSimple(const Ray& ray) {
	glm::vec3 p, n;
	return (glm::intersectRaySphere(ray.p, ray.d, position, radius, p, n));
}

void Cube::draw()
{
	//ofDrawBox(glm::vec3(position.x + width / 2, position.y + height / 2, position.z + depth / 2), width, height, depth);
	for (int i = 0; i < triangleMesh.size(); i++)
	{
		triangleMesh[i].draw();
	}
	for (int i = 0; i < verticies.size(); i++)
	{
		ofDrawSphere(*verticies[i], 0.1);
	}
}

bool Cube::intersect(const Ray& ray, glm::vec3& point, glm::vec3& normal) {
	//slow, naive intersection method
	bool intersected = false;
	float distance = 0;
	for (int i = 0; i < triangleMesh.size(); i++)
	{
		Triangle t = triangleMesh[i];
		glm::vec3 bCoord;

		if (glm::intersectRayTriangle(ray.p, ray.d, *t.points[0], *t.points[1], *t.points[2], bCoord))
		{
			if (!intersected || bCoord.z < distance)
			{
				Ray temp = ray;
				distance = bCoord.z;
				point = temp.evalPoint(distance);
				normal = glm::normalize(glm::cross(glm::vec3(*t.points[2] - *t.points[1]), glm::vec3(*t.points[0] - *t.points[1])));
				intersected = true;
			}
		}
	}
	return intersected;
}

bool Cube::intersectSimple(const Ray& ray)
{
	glm::vec3 p, n;
	return intersect(ray, p, n);
}

void Cube::createMesh()
{
	//0 front left bottom
	verticies.push_back(new glm::vec3(position.x, position.y, position.z + depth));
	//1 front right bottom
	verticies.push_back(new glm::vec3(position.x + width, position.y, position.z + depth));
	//2 front left top
	verticies.push_back(new glm::vec3(position.x, position.y + height, position.z + depth));
	//3 front right top
	verticies.push_back(new glm::vec3(position.x + width, position.y + height, position.z + depth));
	//4 back left bottom
	verticies.push_back(new glm::vec3(position.x, position.y, position.z));
	//5 back right bottom
	verticies.push_back(new glm::vec3(position.x + width, position.y, position.z));
	//6 back left top
	verticies.push_back(new glm::vec3(position.x, position.y + height, position.z));
	//7 back right top
	verticies.push_back(new glm::vec3(position.x + width, position.y + height, position.z));
	//index 0 1 = front face
	triangleMesh.push_back(Triangle(verticies[0], verticies[3], verticies[2]));
	triangleMesh.push_back(Triangle(verticies[0], verticies[1], verticies[3]));
	//index 2 3 = left face
	triangleMesh.push_back(Triangle(verticies[0], verticies[2], verticies[4]));
	triangleMesh.push_back(Triangle(verticies[2], verticies[6], verticies[4]));
	//index 4 5 = back face
	triangleMesh.push_back(Triangle(verticies[6], verticies[7], verticies[5]));
	triangleMesh.push_back(Triangle(verticies[5], verticies[4], verticies[6]));
	//index 6 7 = right face
	triangleMesh.push_back(Triangle(verticies[1], verticies[7], verticies[3]));
	triangleMesh.push_back(Triangle(verticies[1], verticies[5], verticies[7]));
	//index 7 9 = bottom face
	triangleMesh.push_back(Triangle(verticies[5], verticies[1], verticies[0]));
	triangleMesh.push_back(Triangle(verticies[5], verticies[0], verticies[4]));
	//index 10 11 = top face
	triangleMesh.push_back(Triangle(verticies[2], verticies[3], verticies[6]));
	triangleMesh.push_back(Triangle(verticies[3], verticies[7], verticies[6]));
}
#include "Light.h"
#include <math.h>

DirectedAreaLight::DirectedAreaLight(glm::vec3 position, glm::vec3 direction, float radius, float intensity) 
{
	this->position = position;
	this->direction = direction; 
	this->radius = radius, 
	this->intensity = intensity;

	angle = acos(glm::dot(glm::vec3(0, 0, -1), direction) / (glm::length(direction)));
	cross = glm::normalize(glm::cross(glm::vec3(0, 0, -1), direction));
	setNumOfSamplePoints(16,3);
}

DirectedAreaLight::DirectedAreaLight()
{
	position = glm::vec3(0, 0, 0);  
	direction = glm::vec3(0, 1, 0);
	radius = 0.4;
	direction = glm::vec3(0, -1, 0);

	angle = acos(glm::dot(glm::vec3(0, 0, -1), direction) / (glm::length(direction)));
	cross = glm::normalize(glm::cross(glm::vec3(0, 0, -1), direction));
	setNumOfSamplePoints(16,3);
}

void DirectedAreaLight::setNumOfSamplePoints(int num, int rings)
{
	samplePoints.clear();
	vector<glm::vec3> tempPoints;
	// populate a circle with normal of (0,0,1)
	//int rings = 3;
	for (int ringI = 1; ringI <= rings; ringI++)
	{
		int ringLightNum = num / ringI;
		float rPos = radius - radius * (ringI - 1) / rings;
		for (int lightI = 1; lightI <= ringLightNum; lightI++)
		{
			tempPoints.push_back(glm::vec3(rPos * cos((2 * PI / ringLightNum) * lightI), rPos * sin((2 * PI / ringLightNum) * lightI), 0));
		}
	}
	//apply transformations to points
	glm::mat4 m(1.0);
	glm::mat4 translationMatrix = glm::translate(m, position);
	glm::mat4 rotationMatrix = glm::rotate(m, angle, cross);
	for (int i = 0; i < tempPoints.size(); i++)
	{
		glm::vec4 temp = translationMatrix * rotationMatrix * glm::vec4(tempPoints[i], 1);
		samplePoints.push_back(glm::vec3(temp.x, temp.y, temp.z));
	}
	//add one point at center of circle
	samplePoints.push_back(position);
}

void DirectedAreaLight::draw()
{
	for (int i = 0; i < samplePoints.size(); i++)
	{
		ofDrawSphere(samplePoints[i], 0.1);
	}
	ofDrawLine(position, position + glm::normalize(direction));
	ofPushMatrix();
	ofTranslate(position);
	ofRotateRad(angle, cross.x, cross.y, cross.z);
	ofPushMatrix();
	ofDrawCircle(glm::vec3(0,0,0), radius);
	ofPopMatrix();
	ofPopMatrix();
}

// since a point light is either completely obstructed or not at all, this function returns only 1 or 0.
float PointLight::getFracLighted(vector<SceneObject*> objects, glm::vec3 point)
{
	Ray r(point, glm::normalize(position - point));
	for (int objIndex = 0; objIndex < objects.size(); objIndex++) {
		glm::vec3 tPos, tNorm;
		//if ray is intersected, shadow
		if (objects[objIndex]->intersect(r, tPos, tNorm)) {
			return 0;
		}
	}
	return 1;
}

float DirectedAreaLight::getFracLighted(vector<SceneObject*> objects, glm::vec3 point)
{
	int pointsObstructed = 0;
	for (int pointIndex = 0; pointIndex < samplePoints.size(); pointIndex++)
	{
		Ray r(point, glm::normalize(samplePoints[pointIndex] - point));
		for (int objIndex = 0; objIndex < objects.size(); objIndex++) {
			//if ray is intersected, shadow
			if (objects[objIndex]->intersectSimple(r)) {
				pointsObstructed++;
				break;
			}
		}
	}
	return (float)(samplePoints.size()- pointsObstructed)/ samplePoints.size();
}
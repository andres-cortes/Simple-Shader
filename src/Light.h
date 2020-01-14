#pragma once
#include "ofMain.h"
#include "SceneObject.h"
#define PI 3.14159265358979323846

class Light {
public:
	virtual void draw() = 0;
	virtual float getFracLighted(vector<SceneObject*> objects, glm::vec3 point) = 0;
	virtual void setNumOfSamplePoints(int num, int rings) {};
	float intensity = 1;
	float radius = 0.4;
	glm::vec3 position;
	bool hasSmoothShading = false;
};

class PointLight : public Light{
public:
	PointLight(glm::vec3 position, float intensity) { this->position = position; this->intensity = intensity; }
	PointLight() { position = glm::vec3(0, 0, 0); }
	void draw() { ofDrawSphere(position, 0.4); }
	float getFracLighted(vector<SceneObject*> objects, glm::vec3 point);
};

class DirectedAreaLight : public Light {
public:
	DirectedAreaLight(glm::vec3 position, glm::vec3 direction, float radius, float intensity);
	DirectedAreaLight();
	void draw();
	void setNumOfSamplePoints(int num, int rings);
	float getFracLighted(vector<SceneObject*> objects, glm::vec3 point);
	float radius;
	glm::vec3 direction;
	bool hasSmoothShading = true;
private:
	vector<glm::vec3> samplePoints;
	glm::vec3 cross;
	float angle;
};
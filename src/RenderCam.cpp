#include "RenderCam.h"

// Convert (u, v) to (x, y, z) 
// We assume u,v is in [0, 1]
//
glm::vec3 ViewPlane::toWorld(float u, float v) {
	float w = width();
	float h = height();
	return (glm::vec3((u * w) + min.x, (v * h) + min.y, position.z));
}

// Get a ray from the current camera position to the (u, v) position on
// the ViewPlane
//
Ray RenderCam::getRay(float u, float v) {
	glm::vec3 pointOnPlane = view.toWorld(u, v);
	return(Ray(position, glm::normalize(pointOnPlane - position)));
}

void RenderCam::drawFrustum() {
	ofNoFill();
	ofDrawLine(position, glm::vec3(view.min.x, view.min.y, view.position.z));
	ofDrawLine(position, glm::vec3(view.max.x, view.max.y, view.position.z));
	ofDrawLine(position, glm::vec3(view.max.x, view.min.y, view.position.z));
	ofDrawLine(position, glm::vec3(view.min.x, view.max.y, view.position.z));
	//ofDrawTriangle(position, glm::vec3(view.min.x, view.min.y, view.position.z), glm::vec3(view.max.x, view.max.y, view.position.z));
	view.draw();
}

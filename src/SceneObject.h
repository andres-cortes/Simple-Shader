#pragma once
#include "ofMain.h"
#include "Ray.h"
#include "box.h"
//  Base class for any renderable object in the scene
//
class SceneObject {
public:
	virtual void draw() = 0;    // pure virtual funcs - must be overloaded
	virtual bool intersect(const Ray& ray, glm::vec3& point, glm::vec3& normal) { cout << "SceneObject::intersect" << endl; return false; }
	virtual bool intersectSimple(const Ray& ray) { cout << "SceneObject::intersect" << endl; return false; }
	virtual void addTexture(ofImage* img) { texture = img; hasTexture = true; }
	virtual ofColor getTextureColor(glm::vec3& point) { cout << "get texture color at point: " << point << endl; return ofColor::grey; }
	// any data common to all scene objects goes here
	glm::vec3 position = glm::vec3(0, 0, 0);

	// material properties (we will ultimately replace this with a Material class - TBD)
	//
	bool hasTexture = false;
	bool isReflective = false;
	float reflectivePct = 0;
	ofColor diffuseColor = ofColor::grey;    // default colors - can be changed.
	ofColor specularColor = ofColor::lightGray;
protected:
	ofImage * texture;
};

//  General purpose sphere  (assume parametric)
//
class Sphere : public SceneObject {
public:
	Sphere(glm::vec3 p, float r, ofColor diffuse = ofColor::lightGray) { position = p; radius = r; diffuseColor = diffuse; }
	Sphere() {}
	bool intersect(const Ray& ray, glm::vec3& point, glm::vec3& normal);
	bool intersectSimple(const Ray& ray);
	void draw() {
		ofDrawSphere(position, radius);
	}
	float radius = 1.0;
};

class Triangle {
public:
	Triangle(glm::vec3 *p1, glm::vec3 *p2, glm::vec3 *p3) { points.push_back(p1); points.push_back(p2); points.push_back(p3); }
	void draw() { ofDrawTriangle(*points[0], *points[1], *points[2]); }
	vector<glm::vec3 *> points;
};

//  Mesh class (will complete later- this will be a refinement of Mesh from Project 1)
//
class Mesh : public SceneObject {
	bool intersect(const Ray& ray, glm::vec3& point, glm::vec3& normal) { return false; }
	bool intersectSimple(const Ray& ray) { return false; }
	void draw() { }
};


//  General purpose plane 
//
class Plane : public SceneObject {
public:
	Plane(glm::vec3 p, glm::vec3 n, ofColor diffuse = ofColor::darkOliveGreen, float w = 20, float h = 20) {
		position = p; normal = n;
		width = w;
		height = h;
		diffuseColor = diffuse;
		if (normal == glm::vec3(0, 1, 0)) plane.rotateDeg(90, 1, 0, 0);
	}
	Plane() {
		normal = glm::vec3(0, 1, 0);
		plane.rotateDeg(90, 1, 0, 0);
	}

	bool intersect(const Ray& ray, glm::vec3& point, glm::vec3& normal);
	bool intersectSimple(const Ray& ray);
	float sdf(const glm::vec3& p) { return 0; }
	glm::vec3 getNormal(const glm::vec3& p) { return this->normal; }
	void draw() {
		plane.setPosition(position);
		plane.setWidth(width);
		plane.setHeight(height);
		plane.setResolution(16, 16);
		plane.drawWireframe();
	}
	ofColor getTextureColor(glm::vec3& point);
	ofPlanePrimitive plane;
	glm::vec3 normal;

	float width = 20;
	float height = 20;
};

class Cube : public SceneObject {
public:
	Cube(glm::vec3 p, float width, float height, float depth, ofColor diffuse = ofColor::lightGray) {
		position = p, this->width = width, this->height = height, this->depth = depth, diffuseColor = diffuse;
		createMesh();
	}
	Cube() {
		position = glm::vec3(0, 0, 0);  width = 1, height = 1, depth = 1, diffuseColor = ofColor::lightGray;
		createMesh();
	}
	bool intersect(const Ray& ray, glm::vec3& point, glm::vec3& normal);
	bool intersectSimple(const Ray& ray);
	void draw();
	void createMesh();
	float width, height, depth;
	vector<Triangle> triangleMesh;
	vector<glm::vec3 *> verticies;
};
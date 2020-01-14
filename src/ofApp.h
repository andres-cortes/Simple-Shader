//
//  RayCaster - Set of simple classes to create a camera/view setup for our Ray Tracer HW Project
//
//  I've included these classes as a mini-framework for our introductory ray tracer.
//  You are free to modify/change.   
//
//  These classes provide a simple render camera which can can return a ray starting from
//  it's position to a (u, v) coordinate on the view plane.
//
//  The view plane is where we can locate our photorealistic image we are rendering.
//  The field-of-view of the camera by moving it closer/further 
//  from the view plane.  The viewplane can be also resized.  When ray tracing an image, the aspect
//  ratio of the view plane should the be same as your image. So for example, the current view plane
//  default size is ( 6.0 width by 4.0 height ).   A 1200x800 pixel image would have the same
//  aspect ratio.
//
//  This is not a complete ray tracer - just a set of skelton classes to start.  The current
//  base scene object only stores a value for the diffuse/specular color of the object (defaut is gray).
//  at some point, we will want to replace this with a Material class that contains these (and other 
//  parameters)
//  
//  (c) Kevin M. Smith  - 24 September 2018
//
#pragma once

#include "ofMain.h"
#include "Ray.h"
#include "SceneObject.h"
#include "RenderCam.h"
#include "Light.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void rayTrace();
	ofColor shade(Ray r, glm::vec3 pov, int iter);
	double lambert(const glm::vec3& p, const glm::vec3& norm, Light* light);
	double phong(const glm::vec3& p, const glm::vec3& norm, float power, glm::vec3 pov, Light* light);
	//gui
	bool bHide = true;
	ofxFloatSlider diffCoef, specCoef, specPow;
	ofxIntSlider areaLightSamples, areaLightRings;
	ofxToggle msaa4, msaa16;
	ofxPanel gui;
	bool bShowImage = false;
	bool bHasImage = false;
	bool msaa4Prev, msaa16Prev = false;
	//cameras
	ofEasyCam  eCam;
	ofCamera sideCam;
	ofCamera previewCam;
	ofCamera* theCam;    
	//render camera
	RenderCam renderCam;
	//rendered image
	ofImage rImg;
	//objects in scene
	vector<SceneObject*> scene;
	//lights in scene
	vector<Light*> lights;
	ofColor bColor;
	//number of reflections
	int reflectNum;
	//dimensions and location of rendered image
	//note: aspect ratio is 3:2
	int imgWidth = 1200;
	int imgHeight = 800;
	string renderPath;
	//textures
	ofImage floorTexture;
	float renderTime;
};

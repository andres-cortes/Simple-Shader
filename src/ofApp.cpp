#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//*************************initialize all objects in scene***************************
	//
	
	Sphere* s1 =  new Sphere(glm::vec3(0, 0, -2.4), 1);
	s1->specularColor = ofColor::white;
	s1->diffuseColor = ofColor::darkSalmon;
	s1->isReflective = true;
	s1->reflectivePct = 0.2;
	scene.push_back(s1);

	Sphere* s2 = new Sphere(glm::vec3(-2, -0.3, 0.3), 0.7);
	s2->specularColor = ofColor::white;
	s2->diffuseColor = ofColor::lightBlue;
	s2->isReflective = true;
	s2->reflectivePct = 0.2;
	scene.push_back(s2);

	Sphere* s3 = new Sphere(glm::vec3(-1, -0.6, 2.5), 0.4);
	s3->specularColor = ofColor::white;
	s3->diffuseColor = ofColor::darkViolet;
	s3->isReflective = true;
	s3->reflectivePct = 0.2;
	scene.push_back(s3);

	Sphere* s4 = new Sphere(glm::vec3(3, 0.5, -2.5), 1.5);
	s4->specularColor = ofColor::white;
	s4->diffuseColor = ofColor::lightGoldenRodYellow;
	s4->isReflective = true;
	s4->reflectivePct = 0.2;
	scene.push_back(s4);
	
	Sphere* s5 = new Sphere(glm::vec3(-4, 1, -4), 2);
	s5->specularColor = ofColor::white;
	s5->diffuseColor = ofColor::lightCoral;
	s5->isReflective = true;
	s5->reflectivePct = 0.2;
	scene.push_back(s5);

	Sphere* s6 = new Sphere(glm::vec3(3.5, -0.2, 1.8), 0.8);
	s6->specularColor = ofColor::white;
	s6->diffuseColor = ofColor::lightGreen;
	s6->isReflective = true;
	s6->reflectivePct = 0.2;
	scene.push_back(s6);

	Sphere* s7 = new Sphere(glm::vec3(-4.5, -0.1, 1), 0.9);
	s7->specularColor = ofColor::white;
	s7->diffuseColor = ofColor::lightPink;
	s7->isReflective = true;
	s7->reflectivePct = 0.2;
	scene.push_back(s7);

	Sphere* s8 = new Sphere(glm::vec3(-2.5, -0.5, 3.2), 0.5);
	s8->specularColor = ofColor::white;
	s8->diffuseColor = ofColor::aqua;
	s8->isReflective = true;
	s8->reflectivePct = 0.2;
	scene.push_back(s8);
	
	Sphere* s9 = new Sphere(glm::vec3(1, -0.4, 0), 0.6);
	s9->specularColor = ofColor::white;
	s9->diffuseColor = ofColor::lightGray;
	s9->isReflective = true;
	s9->reflectivePct = 0.6;
	scene.push_back(s9);

	Sphere* s10 = new Sphere(glm::vec3(1.5, -0.6, 2), 0.4);
	s10->specularColor = ofColor::white;
	s10->diffuseColor = ofColor::deepSkyBlue;
	s10->isReflective = true;
	s10->reflectivePct = 0.2;
	scene.push_back(s10);
	
	/*
	Cube* c1 = new Cube(glm::vec3(-4, 2, 0), 1, 1, 1, ofColor::red);
	c1->specularColor = ofColor::white;
	c1->isReflective = true;
	c1->reflectivePct = 0.4;
	scene.push_back(c1);

	Cube* c2 = new Cube(glm::vec3(0, 2.5, 0.5), 0.5, 0.5, 0.5, ofColor::blue);
	c2->specularColor = ofColor::white;
	c2->isReflective = true;
	c2->reflectivePct = 0.4;
	scene.push_back(c2);

	Cube* c3 = new Cube(glm::vec3(2, 1.5, 1), 1.5, 1.5, 1.5, ofColor::purple);
	c3->specularColor = ofColor::white;
	c3->isReflective = true;
	c3->reflectivePct = 0.4;
	scene.push_back(c3);

	Cube* c4 = new Cube(glm::vec3(-2, 2, -2), 1.0, 1.0, 1.0, ofColor::green);
	c4->specularColor = ofColor::white;
	c4->isReflective = true;
	c4->reflectivePct = 0.4;
	scene.push_back(c4);

	Cube* c5 = new Cube(glm::vec3(2, -1, 1), 0.5, 0.5, 0.5, ofColor::cyan);
	c5->specularColor = ofColor::white;
	c5->isReflective = true;
	c5->reflectivePct = 0.4;
	//scene.push_back(c5);

	Cube* c6 = new Cube(glm::vec3(-3, -1, 0), 1.5, 1.5, 1.5, ofColor::yellow);
	c6->specularColor = ofColor::white;
	c6->isReflective = true;
	c6->reflectivePct = 0.4;
	//scene.push_back(c6);

	Cube* c7 = new Cube(glm::vec3(-0.5, -1, -4), 3, 3, 3, ofColor::pink);
	c7->specularColor = ofColor::white;
	c7->isReflective = true;
	c7->reflectivePct = 0.4;
	//scene.push_back(c7);
	
	
	Cube* c8 = new Cube(glm::vec3(-20, -1, -8), 40, 20, 0.1, ofColor::white);
	c8->specularColor = ofColor::white;
	c8->isReflective = true;
	c8->reflectivePct = 0.98;
	scene.push_back(c8);
	*/
	Plane* p1 = new Plane(glm::vec3(0, -1, 0), glm::vec3(0, 1, 0),ofColor::dimGrey, 80, 80);
	p1->specularColor = ofColor::white;
	p1->isReflective = true;
	p1->reflectivePct = 0.2;
	floorTexture.load("/images/Marble_Tiles_001_basecolor.jpg");
	//floorTexture.load("/images/Wood_planks_011_basecolor.jpg");
	//floorTexture.load("/images/Tiles_016_basecolor.jpg");
	p1->addTexture(&floorTexture);
	scene.push_back(p1);
	renderPath = "/images/render.png";



	//************************initialize all point lights********************************
	//
	lights.push_back(new DirectedAreaLight(glm::vec3(-5, 8, 8), glm::vec3(5, -8, -8), 1, 6.5));
	lights.push_back(new DirectedAreaLight(glm::vec3(10, 10, 8), glm::vec3(-10,-10,-8), 1, 8.2));
	//lights.push_back(new DirectedAreaLight(glm::vec3(-8, 4, -8), glm::vec3(8, -4, 8), 4, 7));

	//******************************set up cameras***************************************
	eCam.setDistance(50);
	eCam.setNearClip(.1);
	sideCam.setPosition(glm::vec3(12, 0, 0));
	sideCam.lookAt(glm::vec3(0, 0, 0));
	sideCam.setNearClip(.1);
	previewCam.setPosition(glm::vec3(0, 0, 10));
	previewCam.lookAt(glm::vec3(0, 0, 0));
	previewCam.setNearClip(0.1);
	theCam = &eCam;
	bColor = ofColor::black;
	ofSetBackgroundColor(ofColor::black);

	//********************************setup GUI / init constants******************************************
	gui.setup();
	gui.add(diffCoef.setup("Diffuse Coefficient", 0.95, 0, 5));
	gui.add(specCoef.setup("Specular Coefficient", 10, 0, 20));
	gui.add(specPow.setup("Specular Power", 15, 0, 50));
	gui.add(areaLightSamples.setup("Smooth Shadow Samples", 16, 0, 64));
	gui.add(areaLightRings.setup("Smooth Shadow Rings", 3, 1, 16));
	gui.add(msaa4.setup("MSAA x4", false));
	gui.add(msaa16.setup("MSAA x16", false));
	bHide = false;
	reflectNum = 3;
}

void ofApp::update(){
	//get input for number of samples for each area light
	for (int i = 0; i < lights.size(); i++) {
		lights[i]->setNumOfSamplePoints(areaLightSamples, areaLightRings);
	}
	//the following section is to simulate radio buttons (if a button has changed to true, set other button to false)
	//note that we have to check for changes, otherwise other buttons will always be set to false, meaning that we cannot click them
	if (msaa4 && msaa4 != msaa4Prev) {
		msaa16 = false;
		msaa4Prev = true;
		msaa16Prev = false;
	}
	else if (msaa16 && msaa16 != msaa16Prev) {
		msaa4 = false;
		msaa4Prev = false;
		msaa16Prev = true;
	}
}

void ofApp::draw(){
	//*********************************draw GUI*******************************************
	if (!bHide)
		gui.draw();
	theCam->begin();
	//********************************draw axis*******************************************
	ofSetColor(ofColor::red);
	ofDrawLine(glm::vec3(0, 0, 0), glm::vec3(10, 0, 0));
	ofSetColor(ofColor::green);
	ofDrawLine(glm::vec3(0, 0, 0), glm::vec3(0, 10, 0));
	ofSetColor(ofColor::blue);
	ofDrawLine(glm::vec3(0, 0, 0), glm::vec3(0, 0, 10));
	//*************************draw objects in scene**************************************
	ofSetColor(ofColor::white);
	for (int i = 0; i < scene.size(); i++)
	{
		scene.at(i)->draw();
	}
	
	//*****************************draw lights*******************************************
	for (int i = 0; i < lights.size(); i++)
	{
		ofSetColor(ofColor::yellow);
		lights[i]->draw();
	}

	//********************draw render cam and frustum*************************************
	ofSetColor(ofColor::lightBlue);
	renderCam.draw();
	renderCam.drawFrustum();
	ofSetColor(ofColor::white);
	theCam->end();

	//******************draw rendered image on to window**********************************
	if (bShowImage && bHasImage)
	{
		int w = ofGetWidth();
		int h = ofGetHeight();
		rImg.draw(w/2 - rImg.getWidth()/2, h/2 - rImg.getHeight()/2);
	}
}

//******************************key inputs***********************************************
void ofApp::keyPressed(int key){
	switch (key)
	{
	case OF_KEY_F1:
		theCam = &eCam;
		break;
	case OF_KEY_F2:
		theCam = &previewCam;
		break;
	case OF_KEY_F3:
		theCam = &sideCam;
		break;
	case ' ':
		rayTrace();
		bShowImage = true;
		break;
	case 'p':
	case 'P':
		bShowImage = !bShowImage;
		break;
	}
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


//******************************Ray Tracing*****************************************
void ofApp::rayTrace()
{
	std::cout << "Begin Render" << endl;
	renderTime = ofGetElapsedTimeMillis();
	rImg.allocate(imgWidth, imgHeight, OF_IMAGE_COLOR);
	float percent = 10;
	//for each pixel
	for (double picY = 0; picY < imgHeight; picY++) {
		for (double picX = 0; picX < imgWidth; picX++) {
			//*****************Progress percentage***************
			if (picY > imgHeight * percent / 100)
			{
				std::cout << percent << "% completed in: " << (ofGetElapsedTimeMillis() - renderTime) / 1000 << endl;
				percent += 10;
			}
			//******************Anti Aliasing / calling shader*******************
			ofColor pxColor; 
			//MSAA x4, uses flipquad / RGSS pattern (approximately)
			if (msaa4) {
				ofColor tColor = shade(renderCam.getRay((picX + 0.6) / imgWidth, 1 - (picY) / imgHeight), renderCam.position, 0);
				ofColor lColor = shade(renderCam.getRay((picX) / imgWidth, 1 - (picY + 0.4) / imgHeight), renderCam.position, 0);
				ofColor rColor = shade(renderCam.getRay((picX + 0.4) / imgWidth, 1 - (picY + 1) / imgHeight), renderCam.position, 0);
				ofColor bColor = shade(renderCam.getRay((picX + 1) / imgWidth, 1 - (picY + 0.6) / imgHeight), renderCam.position, 0);
				int r = tColor.r + lColor.r + rColor.r + bColor.r;
				int b = tColor.b + lColor.b + rColor.b + bColor.b;
				int g = tColor.g + lColor.g + rColor.g + bColor.g;
				pxColor = ofColor(r / 4, g / 4, b / 4);
			}
			//MSAA x16, uses uniformly distributed grid
			else if (msaa16)
			{
				int r = 0, g = 0, b = 0;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++)
					{
						ofColor tColor = shade(renderCam.getRay((picX + (float)j / 4)/ imgWidth, 1 - (picY + (float)i / 4)/ imgHeight), renderCam.position, 0);
						r += tColor.r;
						b += tColor.b;
						g += tColor.g;
					}
				}
				pxColor = ofColor(r / 16, g / 16, b / 16);
			}
			//no MSAA
			else {
				pxColor = shade(renderCam.getRay((picX + 0.5) / imgWidth, 1 - (picY + 0.5) / imgHeight), renderCam.position, 0);
			}
			rImg.setColor(picX, picY, pxColor);
		}
	}
	//save image, load new image
	rImg.save(renderPath, OF_IMAGE_QUALITY_BEST);
	rImg.load(renderPath);
	bHasImage = true;
	std::cout << "Finished Rendering in " << (ofGetElapsedTimeMillis() - renderTime)/1000 << "s" << endl;
}

ofColor ofApp::shade(Ray r, glm::vec3 pov, int iter)
{
	//get object and point on object closest to view point that intersects the ray (intersectedObj)
	SceneObject* intersectedObj;
	glm::vec3 intersectedObjPt, intersectedObjN, normalTemp, intersectTemp;
	bool intersected = false;
	for (int i = 0; i < scene.size(); i++) {
		if (scene[i]->intersect(r, intersectTemp, normalTemp)) {
			if (!intersected || glm::length(intersectTemp - pov) < glm::length(intersectedObjPt - pov)) {
				intersected = true;
				intersectedObj = scene[i];
				intersectedObjPt = intersectTemp;
				intersectedObjN = normalTemp;
			}
		}
	}
	//if ray intersections object, shade pixel based on intersected Object, point of intersection, and normal at point of intersection
	if (intersected) {
		ofColor diffColor;
		if (intersectedObj->hasTexture) {
			diffColor = intersectedObj->getTextureColor(intersectedObjPt);
		}
		else {
			diffColor = intersectedObj->diffuseColor;
		}
		
		double totalLambert = 0, totalPhong = 0;;
		for (int lightIndex = 0; lightIndex < lights.size(); lightIndex++) {
			// for each light, get ray slightly off the surface
			Ray temp(intersectedObjPt, glm::normalize(lights[lightIndex]->position - intersectedObjPt));
			// get fraction of light covered at current point (shadows)
			float fractionLighted = lights[lightIndex]->getFracLighted(scene, temp.evalPoint(0.001));
			if (fractionLighted > 0.01) {
				// get lambert and phong lighting contributions
				totalLambert += fractionLighted * lambert(intersectedObjPt, intersectedObjN, lights[lightIndex]);
				totalPhong += fractionLighted * phong(intersectedObjPt, intersectedObjN, specPow, pov, lights[lightIndex]);
			}
		}
		ofColor pixelColor = diffColor * totalLambert + intersectedObj->specularColor * totalPhong;
		//recursive reflection
		if (intersectedObj->isReflective && iter < reflectNum) {
			float ref = intersectedObj->reflectivePct;
			glm::vec3 tVec(2 * glm::dot(intersectedObjN, -r.d) * intersectedObjN + r.d);
			Ray tRay(intersectedObjPt, tVec);
			ofColor tColor = shade(Ray(tRay.evalPoint(0.001), tVec), intersectedObjPt, iter + 1);
			pixelColor = ofColor(
				(pixelColor.r * (1.0 - ref) + tColor.r * ref), //color values are clamped, no overflow possible
				(pixelColor.g * (1.0 - ref) + tColor.g * ref),
				(pixelColor.b * (1.0 - ref) + tColor.b * ref));
		}
		return pixelColor;
	}
	else
	{
		// if no intersection, return background color
		return bColor;
	}
}

double ofApp::lambert(const glm::vec3& p, const glm::vec3& norm, Light *light) {
	//calculate L = k(I/r^2)max(0,n(dot)l)
	float r = glm::length(p - light->position);
	double currlightIntensity = diffCoef * (light->intensity) / glm::pow(r, 2);
	double dot = glm::dot(norm, light->position - p);
	if (dot <= 0) {
		currlightIntensity = 0;
	}
	else {
		currlightIntensity = currlightIntensity * dot;
	}
	return currlightIntensity;
}

double ofApp::phong(const glm::vec3& p, const glm::vec3& norm, float power, glm::vec3 pov, Light* light) {
	//calculate L = k(I/r^2)max(n(dot)(h = bisector(v,l))
	glm::vec3 v = pov - p;
	glm::vec3 l = light->position - p;
	glm::vec3 h = (v + l) / glm::length(v + l);
	float r = glm::length(p - light->position);
	double currlightIntensity = specCoef * (light->intensity) / glm::pow(r, 2);
	double dot = glm::dot(glm::normalize(norm), glm::normalize(h));
	if (dot < 0) {
		currlightIntensity = 0;
	}
	else {
		currlightIntensity = currlightIntensity * glm::pow(dot, power);
	}
	return currlightIntensity;
}

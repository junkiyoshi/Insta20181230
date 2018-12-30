#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int deg_span = 15;
	int radius_span = 15;
	for (int radius = 150; radius <= 330; radius += radius_span) {

		for (int deg = 0; deg < 360; deg += deg_span) {

			glm::vec2 noise_point = glm::vec2(
				radius_span * cos((deg + deg_span * 0.5) * DEG_TO_RAD),
				radius_span * sin((deg + deg_span * 0.5) * DEG_TO_RAD));

			vector<glm::vec2> vertices;
			for (int tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg++) {

				vertices.push_back(glm::vec2(radius * cos(tmp_deg * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD)));
			}
			for (int tmp_deg = deg + deg_span; tmp_deg >= deg; tmp_deg--) {

				vertices.push_back(glm::vec2((radius - radius_span) * cos(tmp_deg * DEG_TO_RAD), (radius - radius_span) * sin(tmp_deg * DEG_TO_RAD)));
			}

			float noise_value = ofNoise(radius + noise_point.x * 0.01 + ofGetFrameNum() * 0.01, radius + noise_point.y * 0.01 + ofGetFrameNum() * 0.01);

			noise_value < 0.5 ? ofFill() : ofNoFill();

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
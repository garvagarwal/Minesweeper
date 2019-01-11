#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "cell.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		// Event methods
		void HandleGameEvents(std::string & event);

		// Game parameters
		int board_width_;
		int board_height_;
		int num_mines_;

		std::vector<std::vector<Cell*>> cells;
};

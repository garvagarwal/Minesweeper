#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "cell.h"

#define CELL_OFFSET 0
#define BOARD_OFFSET 25

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		//Game parameters
		int board_width_;
		int board_height_;
		int num_mines_;

		std::vector<std::vector<Cell*>> cells;
};

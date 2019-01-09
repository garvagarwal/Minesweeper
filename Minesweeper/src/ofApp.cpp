#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Minesweeper");

  //Establishes easy board for now
  board_width_ = 9;
  board_height_ = 9;
  num_mines_ = 10;

  //Gets cell data
  ofImage data_cell("Cell.png");
  cell_width_ = data_cell.getWidth();
  cell_height_ = data_cell.getHeight();

  //Adds cells to create selected board
  for (int h = 0; h < board_height_; ++h) {
    std::vector<ofImage> row;

    for (int w = 0; w < board_width_; ++w) {
      ofImage cell("Cell.png");
      row.push_back(cell);
    }

    cells.push_back(row);
  }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  //Draws cells
  for (int h = 0; h < board_height_; ++h) {
    for (int w = 0; w < board_width_; ++w) {
      cells[w][h].draw(w * (cell_width_ + CELL_OFFSET) + BOARD_OFFSET,
                            h * (cell_height_ + CELL_OFFSET) + BOARD_OFFSET);
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  int cellX;
  int cellY;

  if(x > BOARD_OFFSET && x < ofGetWindowWidth() - BOARD_OFFSET) {
    cellX = (x - BOARD_OFFSET) / cell_width_;
  }

  if(y > BOARD_OFFSET && y < ofGetWindowHeight() - BOARD_OFFSET) {
    cellY = (y - BOARD_OFFSET) / cell_height_;
  }

  cells[cellX][cellY].load("CellDown.png");
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

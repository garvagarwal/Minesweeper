#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Minesweeper");

  //Establishes easy board for now
  board_width = 9;
  board_height = 9;
  num_mines = 10;

  //Gets cell data
  ofImage data_cell("Cell.png");
  cell_width = data_cell.getWidth();
  cell_height = data_cell.getHeight();

  //Adds cells to create selected board
  for (int h = 0; h < board_height; ++h) {
    std::vector<ofImage> row;

    for (int w = 0; w < board_width; ++w) {
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
  for (int h = 0; h < board_height; ++h) {
    for (int w = 0; w < board_width; ++w) {
      cells[w][h].draw(w * (cell_width + 1) + 150, h * (cell_height + 1) + 150);
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

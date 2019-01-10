#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Minesweeper");

  // Establishes easy board for now
  board_width_ = 9;
  board_height_ = 9;
  num_mines_ = 10;

  // Adds cells to create selected board
  for (int h = 0; h < board_height_; ++h) {
    std::vector<Cell*> row;

    for (int w = 0; w < board_width_; ++w) {
      Cell *cell = new Cell();
      cell->setup(w * (CELL_WIDTH + CELL_OFFSET) + BOARD_OFFSET,
                            h * (CELL_HEIGHT + CELL_OFFSET) + BOARD_OFFSET);
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
  // Draws cells
  for (int h = 0; h < board_height_; ++h) {
    for (int w = 0; w < board_width_; ++w) {
      cells[w][h]->draw();
    }
  }
}

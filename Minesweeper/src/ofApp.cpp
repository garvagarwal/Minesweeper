#include "ofApp.h"
#include <stdlib.h>
#include <time.h>

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Minesweeper");

  srand(static_cast<unsigned>(time(0)));

  // Establishes easy board for now
  board_width_ = 9;
  board_height_ = 9;
  num_mines_ = 10;

  // Adds cells to create selected board
  for (int h = 0; h < board_height_; ++h) {
    std::vector<Cell*> row;

    for (int w = 0; w < board_width_; ++w) {
      Cell *cell = new Cell();
      cell->setup(w * (CELL_WIDTH + CELL_OFFSET) + BOARD_HORIZONTAL_OFFSET,
                  h * (CELL_HEIGHT + CELL_OFFSET) + BOARD_VERTICAL_OFFSET);

      ofAddListener(cell->game_events, this, &ofApp::HandleGameEvents);
      row.push_back(cell);
    }

    cells.push_back(row);
  }

  for (int m = 0; m < num_mines_; ++m) {
    int rand_x;
    int rand_y;

    do {
      rand_x = rand() % board_width_;
      rand_y = rand() % board_height_;
    } while(cells[rand_y][rand_x]->hidden_state_ != "EmptyCell.png");

    cells[rand_y][rand_x]->hidden_state_ = "Mine.png";
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

// Handles the various game events
void ofApp::HandleGameEvents(std::string & event) {
  if (event == "clicked on mine") {
    for (int h = 0; h < board_height_; ++h) {
      for (int w = 0; w < board_width_; ++w) {
        if (cells[h][w]->hidden_state_ == "Mine.png") {
          cells[h][w]->cur_state_ = "RevealedMineCell.png";
        }
        if (cells[h][w]->cur_state_ == "FlaggedCell.png" &&
            cells[h][w]->hidden_state_ != "Mine.png") {
          cells[h][w]->cur_state_ = "FlaggedWrongCell.png";
        }
      }
    }
  }
}

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

  setupBoard();
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
        if (cells[h][w]->mine_ && cells[h][w]->cur_state_ == "Cell.png") {
          cells[h][w]->cur_state_ = "RevealedMineCell.png";
        }
        if (cells[h][w]->cur_state_ == "FlaggedCell.png" &&
            !cells[h][w]->mine_) {
          cells[h][w]->cur_state_ = "FlaggedWrongCell.png";
        }
      }
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  switch (key) {
    case 101:
      board_width_ = 9;
      board_height_ = 9;
      num_mines_ = 10;
      setupBoard();
      break;

    case 109:
      board_width_ = 16;
      board_height_ = 16;
      num_mines_ = 40;
      setupBoard();
      break;

    case 104:
      board_width_ = 30;
      board_height_ = 16;
      num_mines_ = 99;
      setupBoard();
      break;

    case 110:
      setupBoard();
      break;
  }
}

// Setup function, acts like a reset for the board
void ofApp::setupBoard() {
  ofSetWindowShape(2 * BOARD_HORIZONTAL_OFFSET + board_width_ * CELL_WIDTH, 
                   BOARD_HORIZONTAL_OFFSET + BOARD_VERTICAL_OFFSET + 
                   board_height_ * CELL_HEIGHT);

  // Adds cells to create selected board
  cells.clear();

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

  std::cout << "3" << std::endl;

  // Randomly assign mines to cells
  for (int m = 0; m < num_mines_; ++m) {
    int rand_x;
    int rand_y;

    do {
      rand_x = rand() % board_width_;
      rand_y = rand() % board_height_;
    } while(cells[rand_y][rand_x]->mine_);

    cells[rand_y][rand_x]->mine_ = true;
  }

  std::cout << "4" << std::endl;

  // Assign numbers based off nearby mines
  for (int h = 0; h < board_height_; ++h) {
    std::cout << "row" << std::endl;
    for (int w = 0; w < board_width_; ++w) {
      int mines = 0;
      bool left = false, right = false, top = false, bot = false;

      if (w - 1 >= 0) left = true;
      if (w + 1 < board_width_) right = true;
      if (h - 1 >= 0) top = true;
      if (h + 1 < board_height_) bot = true;

      if (left) {
        mines += (cells[h][w - 1]->mine_ ? 1 : 0);
      }

      if (right) {
        mines += (cells[h][w + 1]->mine_ ? 1 : 0);
      }

      if (top) {
        mines += (cells[h - 1][w]->mine_ ? 1 : 0);
      }

      if (bot) {
        mines += (cells[h + 1][w]->mine_ ? 1 : 0);
      }

      if (left && top) {
        mines += (cells[h - 1][w - 1]->mine_ ? 1 : 0);
      }

      if (left && bot) {
        mines += (cells[h + 1][w - 1]->mine_ ? 1 : 0);
      }

      if (right && top) {
        mines += (cells[h - 1][w + 1]->mine_ ? 1 : 0);
      }

      if (right && bot) {
        mines += (cells[h + 1][w + 1]->mine_ ? 1 : 0);
      }

      cells[h][w]->neighboring_mines_ = mines;
    }
  }

  std::cout << "we made it" << std::endl;
}

#include "cell.h"

Cell::Cell() {
  bRegisteredEvents = false;
}

Cell::~Cell() {
  clear();
}

void Cell::setup(int x, int y) {
  x_pos_ = x;
  y_pos_ = y;
  cur_state_ = "Cell.png";
  hidden_state_ = "EmptyCell.png";
  if(!bRegisteredEvents) {
        ofRegisterMouseEvents(this); // Enable to listen to the mouse events.
        bRegisteredEvents = true;
  }
}

void Cell::draw() {
  ofImage(cur_state_).draw(x_pos_, y_pos_);
}

void Cell::clear(){
  if(bRegisteredEvents) {
    ofUnregisterMouseEvents(this); // disable listening to mouse events.
    bRegisteredEvents = false;
  }
}

void Cell::AssignNeighbors(int num_mines) {
  neighboring_mines_ = num_mines;
}

void Cell::mouseMoved(ofMouseEventArgs & args) {}

void Cell::mouseDragged(ofMouseEventArgs & args) {
  // if (inside(args.x, args.y)) {
  //   if (!mouse_inside_) {
  //     mouse_inside_ = true;
  //     state_ = "CellDown.png";
  //   }
  // } else {
  //   if (mouse_inside_) {
  //     mouse_inside_ = false;
  //     state_ = "Cell.png";
  //   }
  // }
}

void Cell::mousePressed(ofMouseEventArgs & args) {
  // if (inside(args.x, args.y)) {
  //   mouse_inside_ = true;
  //   state_ = "CellDown.png";
  // }
}

void Cell::mouseReleased(ofMouseEventArgs & args) {
  if (inside(args.x, args.y)) {
    std::cout << neighboring_mines_ << '\n';
    if (cur_state_ == "Cell.png") {
      if (args.button == 0) {
        if (hidden_state_ == "Mine.png") {
          cur_state_ = "ExplodedMineCell.png";
          std::string event("clicked on mine");
          ofNotifyEvent(game_events, event);
        }
        cur_state_ = hidden_state_;
      } else if (args.button == 2) {
        cur_state_ = "FlaggedCell.png";
      }
    } else if (cur_state_ == "FlaggedCell.png") {
      if (args.button == 2) {
        cur_state_ = "Cell.png";
      }
    }
  }
}

void Cell::mouseScrolled(ofMouseEventArgs & args) {

}

void Cell::mouseEntered(ofMouseEventArgs & args) {}

void Cell::mouseExited(ofMouseEventArgs & args) {}

bool Cell::inside(float x, float y) {
  return ((x > x_pos_ && x < x_pos_ + CELL_WIDTH) &&
          (y > y_pos_ && y < y_pos_ + CELL_HEIGHT));
}

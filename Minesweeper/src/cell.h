#ifndef CELL_H
#define CELL_H

#include "ofMain.h"

#define CELL_WIDTH ofImage("Cell.png").getWidth()
#define CELL_HEIGHT ofImage("Cell.png").getHeight()
#define CELL_OFFSET 0
#define BOARD_VERTICAL_OFFSET 25
#define BOARD_HORIZONTAL_OFFSET 25

class Cell {
public:
  Cell();
  ~Cell();

  ofEvent<std::string> game_events;

  void setup(int x, int y);
  void draw();
  void clear();
  void AssignNeighbors(int num_mines);

  void mouseMoved(ofMouseEventArgs & args);
  void mouseDragged(ofMouseEventArgs & args);
  void mousePressed(ofMouseEventArgs & args);
  void mouseReleased(ofMouseEventArgs & args);
  void mouseScrolled(ofMouseEventArgs & args);
  void mouseEntered(ofMouseEventArgs & args);
  void mouseExited(ofMouseEventArgs & args);

  //Checks if point is in cell
  bool inside(float x, float y);

  static int clicks_;
  int x_pos_, y_pos_;         // Upper left corner pos of cell
  int neighboring_mines_;      // Number of nearby mines
  std::string cur_state_, hidden_state_;         // Which image to display

protected:
  bool bRegisteredEvents;
};

#endif

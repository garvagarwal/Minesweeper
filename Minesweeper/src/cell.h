##ifndef CELL_H
#define CELL_H

#include "ofMain.h"

class Cell {
public:
  Cell();
  ~Cell();

  ofEvent<ofImage> clickedInside;

  void setup(int x, int y);
  void draw();
  void clear();

  void mouseMoved(ofMouseEventArgs & args);
  void mouseDragged(ofMouseEventArgs & args);
  void mousePressed(ofMouseEventArgs & args);
  void mouseReleased(ofMouseEventArgs & args);
  void mouseScrolled(ofMouseEventArgs & args);
  void mouseEntered(ofMouseEventArgs & args);
  void mouseExited(ofMouseEventArgs & args);

  //Checks if point is in cell
  bool inside(float x, float y);

  int cell_x_, cell_y_;

protected:
  bool bRegisteredEvents;
}

#endif

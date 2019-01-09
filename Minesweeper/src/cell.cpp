#include "cell.h"

Cell::Cell() {
  bRegisteredEvents = false;
}

Cell::~Cell() {
  clear();
}

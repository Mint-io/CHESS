#ifndef GRAPHICALDISPLAY_H
#define GRAPHICALDISPLAY_H
#include <cstddef>
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include "window.h"
class Xwindow;

class GraphicalDisplay{

protected:
    Xwindow w{521,521};

public:
    // Constructors
    GraphicalDisplay();
    // Member Functions
    void notifyDisplay(char cell, int x, int y);

};

#endif

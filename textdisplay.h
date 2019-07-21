#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include <cstddef>
#include <memory>
#include <string>

// Below are global constants
const int ROW = 8;
const int COLUMN = 8;
const int GRIDSIZE = 8;

class TextDisplay {
    std::vector< std::vector<char> > theDisplay;

public:
    // Constructors
    TextDisplay(); 
    // Member functions
    void notify(char type, int x, int y);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif

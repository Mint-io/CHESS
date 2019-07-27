#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <cstddef>
#include <memory>
#include <string>

class TextDisplay;
class GraphicalDisplay;

class Cell {
    char occupy;
    int x;
    int y;

public:
    // Accessors and Mutators of private fields
    char getOccupy();
    int getX();
    int getY();
    void setOccupy(char occupy);
    void setX(int x);
    void setY(int y);
    // Constructors
    Cell(char occupy, int x, int y);
    // Member functions
    void notifyDualDisplay(std::shared_ptr<GraphicalDisplay> gd, std::shared_ptr<TextDisplay> td);
};

bool operator==(Cell c1, Cell c2) {
    return 
    c1.getOccupy() == c2.getOccupy() &&
    c1.getX() == c2.getX() &&
    c1.getY() == c2.getY();
}

#endif

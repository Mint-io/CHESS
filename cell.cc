#include "cell.h"
#include "graphicaldisplay.h"
#include "textdisplay.h"

// Accessors and Mutators of private fields
char Cell::getOccupy() {
    return this->occupy;
}
int Cell::getX() {
    return this->x;
}
int Cell::getY() {
    return this->y;
}
void Cell::setOccupy(char occupy) {
    this->occupy = occupy;
}
void Cell::setX(int x) {
    this->x = x;
}
void Cell::setY(int y) {
    this->y = y;
}
// Constructors
Cell::Cell(char occupy, int x, int y) : occupy{occupy}, x{x}, y{y} {}
// Member functions
void Cell::notifyDualDisplay(std::shared_ptr<GraphicalDisplay> gd, std::shared_ptr<TextDisplay> td) {
    td->notify(this->occupy, this->x, this->y);
    td->notify(this->occupy, this->x, this->y);
}

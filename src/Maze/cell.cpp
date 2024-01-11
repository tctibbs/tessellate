#include "cell.h"

// Constructor
Cell::Cell(int width, int height) {
    width = width;
    height = height;
}

// Destructor
Cell::~Cell() {}

// Set the width of the cell
void Cell::setWidth(int width) {
    this->width = width;
}

// Set the height of the cell
void Cell::setHeight(int height) {
    this->height = height;
}

// Calculate and return the area of the cell
int Cell::getArea() {
    return width * height;
}
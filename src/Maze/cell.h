#pragma once

class Cell {
public:
    // Constructor
    explicit Cell(int width = 0, int height = 0);

    // Destructor
    ~Cell();

    // Member functions
    void setWidth(int width);
    void setHeight(int height);
    auto getArea() -> int;

private:
    int width;
    int height;
};


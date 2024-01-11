class Cell {
public:
    // Constructor
    Cell(int width = 0, int height = 0);

    // Destructor
    ~Cell();

    // Member functions
    void setWidth(int width);
    void setHeight(int height);
    int getArea();

private:
    int width;
    int height;
};


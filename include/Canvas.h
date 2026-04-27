#ifndef CANVAS_H
#define CANVAS_H

#include <string>
#include <vector>

class Canvas {
private:
    int width;
    int height;
    std::vector<std::string> pixels;

public:
    Canvas(int width, int height);

    void clear();
    void setPixel(int x, int y, char symbol);
    void print() const;
};

#endif

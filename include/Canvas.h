#ifndef CANVAS_H
#define CANVAS_H

#include <string>
#include <vector>

class Canvas {
private:
    int width;
    int height;
    char backgroundSymbol;
    std::vector<std::string> pixels;

public:
    Canvas(int width = 40, int height = 20, char backgroundSymbol = ' ');

    void resize(int newWidth, int newHeight, char fillSymbol = ' ');
    void clear();
    void setPixel(int x, int y, char symbol);
    char getPixel(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
    const std::vector<std::string>& getRows() const;
    void setRows(const std::vector<std::string>& rows);
};

#endif

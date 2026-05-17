#include "Canvas.h"
#include "FileManager.h"

#include <cstdio>

int main() {
    const char* fileName = "scenario_art.txt";
    Canvas canvas(4, 2, '.');
    FileManager files;

    canvas.setPixel(0, 0, 'X');
    canvas.setPixel(3, 1, '#');

    if (!files.saveCanvas(canvas, fileName)) {
        return 1;
    }

    Canvas loaded(1, 1, '.');
    if (!files.loadCanvas(loaded, fileName)) {
        return 2;
    }

    std::remove(fileName);

    if (loaded.getPixel(0, 0) != 'X') {
        return 3;
    }
    if (loaded.getPixel(3, 1) != '#') {
        return 4;
    }

    return 0;
}

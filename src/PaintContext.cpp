#include "PaintContext.h"

PaintContext::PaintContext()
    : canvas(40, 20),
      brushSymbol('#'),
      running(true),
      lastMessage("Ready") {
}

Canvas& PaintContext::getCanvas() {
    return canvas;
}

const Canvas& PaintContext::getCanvas() const {
    return canvas;
}

char PaintContext::getBrushSymbol() const {
    return brushSymbol;
}

bool PaintContext::isRunning() const {
    return running;
}

const std::string& PaintContext::getLastMessage() const {
    return lastMessage;
}

void PaintContext::createCanvas(int width, int height) {
    canvas.resize(width, height);
    lastMessage = "Canvas created";
}

void PaintContext::setBrushSymbol(char symbol) {
    brushSymbol = symbol;
    lastMessage = "Brush changed";
}

void PaintContext::drawPoint(int x, int y, char symbol) {
    if (!canvas.contains(x, y)) {
        lastMessage = "Coordinates out of bounds";
        return;
    }

    drawer.drawPoint(canvas, x, y, symbol);
    lastMessage = "Point drawn";
}

void PaintContext::drawLine(int x1, int y1, int x2, int y2, char symbol) {
    if (!canvas.contains(x1, y1) || !canvas.contains(x2, y2)) {
        lastMessage = "Coordinates out of bounds";
        return;
    }

    drawer.drawLine(canvas, x1, y1, x2, y2, symbol);
    lastMessage = "Line drawn";
}

void PaintContext::drawRectangle(int x1, int y1, int x2, int y2, char symbol) {
    if (!canvas.contains(x1, y1) || !canvas.contains(x2, y2)) {
        lastMessage = "Coordinates out of bounds";
        return;
    }

    drawer.drawRectangle(canvas, x1, y1, x2, y2, symbol);
    lastMessage = "Rectangle drawn";
}

void PaintContext::fill(int x, int y, char symbol) {
    if (!canvas.contains(x, y)) {
        lastMessage = "Coordinates out of bounds";
        return;
    }

    fillStrategy.fill(canvas, x, y, symbol);
    lastMessage = "Area filled";
}

void PaintContext::clear() {
    canvas.clear();
    lastMessage = "Canvas cleared";
}

bool PaintContext::save(const std::string& filePath) const {
    return fileManager.saveCanvas(canvas, filePath);
}

bool PaintContext::load(const std::string& filePath) {
    const bool loaded = fileManager.loadCanvas(canvas, filePath);
    lastMessage = loaded ? "Canvas loaded" : "Cannot load file";
    return loaded;
}

void PaintContext::stop() {
    running = false;
    lastMessage = "Goodbye";
}

void PaintContext::setLastMessage(const std::string& message) {
    lastMessage = message;
}

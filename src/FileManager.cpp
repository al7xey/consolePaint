#include "FileManager.h"

#include <fstream>
#include <string>
#include <vector>

bool FileManager::saveCanvas(const Canvas& canvas, const std::string& filePath) const {
    std::ofstream output(filePath);
    if (!output) {
        return false;
    }

    for (const std::string& row : canvas.getRows()) {
        output << row << '\n';
    }

    return true;
}

bool FileManager::loadCanvas(Canvas& canvas, const std::string& filePath) const {
    std::ifstream input(filePath);
    if (!input) {
        return false;
    }

    std::vector<std::string> rows;
    std::string row;
    while (std::getline(input, row)) {
        if (!row.empty() && row.back() == '\r') {
            row.pop_back();
        }
        rows.push_back(row);
    }

    if (rows.empty()) {
        return false;
    }

    const int oldWidth = canvas.getWidth();
    const int oldHeight = canvas.getHeight();
    canvas.setRows(rows);

    return canvas.getWidth() != oldWidth || canvas.getHeight() != oldHeight || canvas.getRows() == rows;
}

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Canvas.h"

#include <string>

class FileManager {
public:
    bool saveCanvas(const Canvas& canvas, const std::string& filePath) const;
    bool loadCanvas(Canvas& canvas, const std::string& filePath) const;
};

#endif

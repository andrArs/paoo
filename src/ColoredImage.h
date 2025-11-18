#ifndef COLOREDIMAGE_H
#define COLOREDIMAGE_H

#include "Image.h"
#include <iostream>

class ColoredImage : public Image {
private:
    int colorDepth; 

public:
    ColoredImage(const std::string& fname = "", const unsigned char* p = nullptr,
                 int s = 0, int depth = 24);

    ColoredImage(const ColoredImage& other);
    ColoredImage& operator=(const ColoredImage& other);

    void print() const;
};

#endif

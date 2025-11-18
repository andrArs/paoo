#include "ColoredImage.h"

using namespace std;

ColoredImage::ColoredImage(const string& fname, const unsigned char* p, int s, int depth)
    : Image(fname, p, s), colorDepth(depth) {
        cout << "\nConstructor: Creating ColoredImage: " << fname << ", depth: " << colorDepth << " bits" << endl;
    }

ColoredImage::ColoredImage(const ColoredImage& other)
    : Image(other),
      colorDepth(other.colorDepth) {
    cout << "\nCopy Constructor: Copying ColoredImage: " << other.getFilename() << endl;
      }


ColoredImage& ColoredImage::operator=(const ColoredImage& other)
{
    if (this == &other) return *this; 

    cout << "\nOperator=: Assigning ColoredImage: " << other.getFilename() << " to " << getFilename() << endl;
    Image::operator=(other);          
    colorDepth = other.colorDepth;    

    return *this;                     
}

void ColoredImage::print() const {
    Image::print();
    cout << "Color Depth: " << colorDepth << " bits\n";
}

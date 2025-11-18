#include "Image.h"
#include <iostream>

using namespace std;

Image::Image(const string& fname, const unsigned char* p, int s)
    : filename(fname), size(s)
{
    cout << "\nConstructor: Creating Image: " << fname << ", size: " << size << endl;

    if (size > 0 && p != nullptr) {
        pixels = new unsigned char[size];
        cout << "Constructor: Allocating " << size << " bytes for pixels\n";
        for (int i = 0; i < size; i++)
            pixels[i] = p[i];
        cout << "Constructor: Pixel data copied\n";
    } else {
        pixels = nullptr;
        cout << "Constructor: No pixel data provided, pixels set to nullptr\n";
    }
}

// Copy constructor - deep copy
Image::Image(const Image& other)
{
    cout << "\nCopy Constructor: Copying Image: " << other.filename << endl;

    filename = other.filename;
    size = other.size;

    if (other.pixels != nullptr) {
        pixels = new unsigned char[size];
        for (int i = 0; i < size; i++)
            pixels[i] = other.pixels[i];
        cout << "Copy Constructor: Pixel data copied\n";
    } else {
        pixels = nullptr;
        cout << "Copy Constructor: Other image has no pixel data\n";
    }
}

// Assignment operator 
Image& Image::operator=(const Image& other)
{
    cout << "\nOperator=: Assigning Image: " << other.filename << " to " << filename << endl;

    if (this == &other) {
        cout << "Operator=: Self-assignment detected, nothing done\n";
        return *this;
    }

    delete[] pixels;
    cout << "Operator=: Old pixel data deleted\n";

    filename = other.filename;
    size = other.size;

    if (other.pixels != nullptr) {
        pixels = new unsigned char[size];
        for (int i = 0; i < size; i++)
            pixels[i] = other.pixels[i];
        cout << "Operator=: Pixel data copied\n";
    } else {
        pixels = nullptr;
        cout << "Operator=: Other image has no pixel data, pixels set to nullptr\n";
    }

    // allow chaining
    return *this;
}

Image::~Image()
{
    cout << "\nDestructor: Destroying Image: " << filename << endl;
    delete[] pixels;
}

void Image::print() const
{
    cout << "\nImage: " << filename << ", Size: ";
    if (pixels == nullptr) {
        cout << "(empty)\n";
        return;
    }

    cout << size << " bytes, Pixels: ";
    for (int i = 0; i < size; i++)
        cout << static_cast<int>(pixels[i]) << " ";
    cout << "\n";
}

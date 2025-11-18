#ifndef IMAGE_H
#define IMAGE_H
#include <string>

class Image {
private:
    std::string filename;
    unsigned char* pixels; 
    int size;              

public:
    Image(const std::string& fname = "", const unsigned char* p = nullptr, int s = 0);
    Image(const Image& other);
    Image& operator=(const Image& other);
    ~Image();

    void print() const;
};

#endif

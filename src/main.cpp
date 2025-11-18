#include "Image.h"
// #include "ColoredImage.h"
#include <iostream>

int main() {

    std::cout << "ITEM 10: Assignment operators return *this\n";

    unsigned char p_template[] = {100, 101, 102};
    Image template_image("Template.png", p_template, 3);

    unsigned char p1[] = {255, 128, 0};
    unsigned char p2[] = {10, 20, 30};

    Image img1("Landscape.png", p1, 3);
    Image img2("Icon.bmp", p2, 3);

    std::cout << "\nChaining assignment: img1 = img2 = template_image\n";
    img1 = img2 = template_image;

    img1.print();
    img2.print();
    template_image.print();

    std::cout << "\nITEM 11: Handle assignment to self\n";

    Image self_image("SelfAssign.png", p1, 3);
    self_image = self_image; // self assignment
    self_image.print();

    std::cout << "\nITEM 12: Copy all parts (base class)\n";

    Image original("Original.png", p2, 3);
    Image backup("Backup.png", nullptr, 0);

    backup = original;
    original.print();
    backup.print();

    return 0;
}

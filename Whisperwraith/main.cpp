#include <iostream>
#include <string>

#include <sail-c++/sail-c++.h>

int main(int argc, char* argv[])
{
    std::string path = "C:/Users/Jonat/Documents/IMG20230715145826_01.jpg";
    sail::image image = sail::image(path);

    std::cout
        << "Size: "
        << image.width() << 'x' << image.height()
        << ", bytes per line: "
        << image.bytes_per_line()
        << ", pixel format: "
        << image.pixel_format()
        << ", pixels: "
        << image.pixels()
        << std::endl;

    return 0;
}
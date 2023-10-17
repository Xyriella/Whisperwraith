#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char* argv[])
{
    std::string img_path = "C:/Users/Jonat/Documents/IMG20230715145826_01.jpg";
    int texWidth, texHeight, texChannels;
    stbi_uc* pixels = stbi_load(img_path.c_str(), &texWidth, &texHeight, &texChannels, STBI_rgb_alpha);
    
    std::cout
        << "Size: "
        << texWidth << 'x' << texHeight
        << std::endl;

    return 0;
}
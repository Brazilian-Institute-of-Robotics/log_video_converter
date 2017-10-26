#include <iostream>
#include <log2video/Converter.hpp>

int main(int argc, char** argv)
{
    if(argc < 4)
    {
        std::cout << "Usage: " << std::endl;
        std::cout << "Log2Video <input_log_file> <stream_name> <output_file> " << std::endl;
        std::cout << "Example: Log2Video camera_aravis_front_left.0.log camera_aravis_front_left.frame ./camera_aravis_front_left.mkv" << std::endl;
        return 0;
    }

    log2video::Converter converter;
    converter.convert(argv[1], argv[2], argv[3]); 

    return 0;
}

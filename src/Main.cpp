#include <iostream>
#include <log2video/Converter.hpp>

int main(int argc, char** argv)
{
    if(argc != 3 and argc != 4)
    {
        std::cout << "Usage: " << std::endl;
        std::cout << "Log2Video <input_log_file> <output_file> [<stream_name>]" << std::endl;
        std::cout << "Example: Log2Video camera_aravis_front_left.0.log ./camera_aravis_front_left.mkv" << std::endl;
        return 0;
    }

    log2video::Converter converter;

    if (argc == 3)
        converter.convert(argv[1], argv[2]); 
    else if (argc == 4)
        converter.convert(argv[1], argv[2], argv[3]); 

    return 0;
}

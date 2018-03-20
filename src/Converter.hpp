#ifndef _LOG2VIDEO_CONVERTER_HPP_
#define _LOG2VIDEO_CONVERTER_HPP_

#include <iostream>
#include "pocolog_cpp/InputDataStream.hpp"
#include "pocolog_cpp/LogFile.hpp"
#include "base/samples/Frame.hpp"


namespace log2video
{
    class Converter
    {
        public:
            Converter();

            void convert(const std::string &input_file, 
                         const std::string &output_file, 
                         std::string stream_name = "");

        private:
            double computeFPS(pocolog_cpp::InputDataStream* frame_stream, 
                              const size_t number_of_samples);
            void getResolution(pocolog_cpp::InputDataStream* frame_stream, 
                               int &width, int &height);

    };

} // end namespace log2video

#endif // _LOG2VIDEO_CONVERTER_HPP

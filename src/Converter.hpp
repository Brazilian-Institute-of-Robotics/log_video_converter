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

            void convert(const std::string &input_file, const std::string &stream, const std::string &output_file);

        private:
            double computeFPS(const pocolog_cpp::InputDataStream* frame_stream, const size_t number_of_samples) const;
            void getResolution(const pocolog_cpp::InputDataStream* frame_stream, int &width, int &height) const;
            pocolog_cpp::InputDataStream* frame_stream_;

    };

} // end namespace log2video

#endif // _LOG2VIDEO_CONVERTER_HPP

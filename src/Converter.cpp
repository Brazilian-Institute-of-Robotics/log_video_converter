#include "Converter.hpp"
#include "frame_helper/FrameHelper.h"
#include "base-logging/Logging.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

namespace log2video
{

Converter::Converter()
{

}

void Converter::convert(const std::string &input_file, const std::string &stream, const std::string &output_file)
{

    std::cout << "Reading input file: " << input_file << std::endl;
    pocolog_cpp::LogFile log_file_(input_file.c_str());

    frame_stream_ = dynamic_cast<pocolog_cpp::InputDataStream*>(&log_file_.getStream(stream));
    // get total number of samples
    size_t samples = frame_stream_->getSize();

    // get frames resolution
    int width, height;
    getResolution(frame_stream_, width, height);

    //Compute FPS
    double fps = computeFPS(frame_stream_, samples);

    cv::VideoWriter output_video(output_file, CV_FOURCC('M','P','4','2'), fps,
            cv::Size(width, height));

    if(!output_video.isOpened())
        throw std::runtime_error("The output video was not correctly opened");

    std::cout << "Output video: " << output_file << std::endl;
    std::cout << "fps: " << fps << std::endl;
    std::cout << "Total number of frames: " << samples << std::endl;
    std::cout << "Frames resolution: " << width << " x " << height << std::endl;

    for( size_t index = 0; index < samples; ++index)
    {
        try
        {
            base::samples::frame::Frame input_frame;
            frame_stream_->getSample<base::samples::frame::Frame>(input_frame, index);

            //convert to RBG
            base::samples::frame::Frame input_frame_rgb;
            input_frame_rgb.init(input_frame.size.width, input_frame.size.height, 8, base::samples::frame::MODE_BGR);
            frame_helper::FrameHelper helper;
            helper.convert( input_frame, input_frame_rgb, 0, 0, frame_helper::INTER_LINEAR, false);

            cv::Mat image = frame_helper::FrameHelper::convertToCvMat(input_frame_rgb);
            output_video << image;
        }
        catch(std::runtime_error &e)
        {
            LOG_WARN(e.what());
        }

        std::cout << "Progress: " << int((((double)index+1.0)/(double)samples)*100.0) << " % \r";
        std::cout.flush();
    }
    std::cout << "Convertion is done." << std::endl;
}

double Converter::computeFPS(const pocolog_cpp::InputDataStream* frame_stream, const size_t number_of_samples) const
{
    base::samples::frame::Frame temp_frame;

    // Get time of first and last frame
    frame_stream_->getSample<base::samples::frame::Frame>(temp_frame, 0);
    base::Time start = temp_frame.time;
    frame_stream_->getSample<base::samples::frame::Frame>(temp_frame, number_of_samples-1);
    base::Time final = temp_frame.time;

    //Compute FPS
    return (number_of_samples/(final - start).toSeconds());
}

void Converter::getResolution(const pocolog_cpp::InputDataStream* frame_stream, int &width, int &height) const
{
    // Get time in seconds and image width and heigth
    base::samples::frame::Frame temp_frame;
    frame_stream_->getSample<base::samples::frame::Frame>(temp_frame, 0);
    width = temp_frame.getWidth();
    height = temp_frame.getHeight();
}
}

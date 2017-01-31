rock_library(log2video
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(log2video_bin Main.cpp
    DEPS log2video)


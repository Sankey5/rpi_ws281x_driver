cmake_minimum_required(VERSION 3.10)

project(rpi_ws281x_driver VERSION 0.1.1)

# Variables mirrored from rpi_ws281x cmake file
set(LIB_TARGET ws2811)

# Add the rpi_ws2811 library (executes the underlying CMakeLists.txt file)
add_subdirectory(rpi_ws281x)
add_subdirectory(controls)
add_subdirectory(patterns)

# Create the object file for main executable
add_executable(rpi_ws281x_driver main.c)

# Add link libraries from the ws281x library
target_link_libraries(rpi_ws281x_driver PUBLIC ${LIB_TARGET}
                                                controls
                                                patterns)

target_include_directories(rpi_ws281x_driver PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/${LIB_TARGET}"
                           )
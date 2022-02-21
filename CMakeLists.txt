add_library(Numbers numbers.h numbers.cpp)
add_executable(Main main.cpp)
target_link_libraries(Main Numbers)
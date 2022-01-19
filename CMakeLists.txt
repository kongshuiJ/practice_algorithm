cmake_minimum_required (VERSION 2.6)
project (Tutorial)

include_directories(commonUtils)

add_executable(test test.cpp)
add_executable(count_sort sort/count_sort.cpp)
add_executable(leetcode_652 src/leetcode_652.cpp)
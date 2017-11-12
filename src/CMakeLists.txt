INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/common)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/algorithm)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/json)
SET(SRC_LIST main.cpp
    algorithm/window.cpp
    common/global_function.cpp
    json/cJSON.c
    )
ADD_COMPILE_OPTIONS(-std=c++11)
ADD_EXECUTABLE(filter ${SRC_LIST})

cmake_minimum_required(VERSION 3.10)

project(KGo-game
    VERSION 0.1.20240904
    DESCRIPTION "Main game"
)

########## Game ########################################

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME})

set(source "src")
set(main "${source}/main")
set(maindev "${main}/sources")
set(kgo "kgo")

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_sources(${PROJECT_NAME}
    PRIVATE ${maindev}/${kgo}/KGoApplication.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${main}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt5::Widgets
)

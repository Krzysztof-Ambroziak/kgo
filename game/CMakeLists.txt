cmake_minimum_required(VERSION 3.10)

project(KGo-game
    VERSION 0.1.20240904
    DESCRIPTION "Main game"
)

########## Game ########################################

# set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME})

set(source "src")
set(main "${source}/main")
set(maindev "${main}/sources")
set(mainres "${main}/resources")
set(kgo "kgo")
set(models "models")
set(go "go")
set(gui "gui")
set(renderers "renderers")
set(services "services")

qt5_add_resources(RESOURCES
   ${mainres}/assets.qrc
)

set_property(TARGET ${PROJECT_NAME}
    PROPERTY AUTOMOC ON)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_sources(${PROJECT_NAME}
    PRIVATE ${maindev}/${kgo}/KGoApplication.hpp
    PRIVATE ${maindev}/${kgo}/KGoApplication.cpp
    PRIVATE ${maindev}/${gui}/Board.hpp
    PRIVATE ${maindev}/${gui}/Board.cpp
    PRIVATE ${maindev}/${gui}/MainWindow.hpp
    PRIVATE ${maindev}/${gui}/MainWindow.cpp
    PRIVATE ${maindev}/${models}/IBoardModel.hpp
    PRIVATE ${maindev}/${models}/BoardModel.hpp
    PRIVATE ${maindev}/${models}/BoardModel.cpp
    PRIVATE ${maindev}/${renderers}/IRenderer.hpp
    PRIVATE ${maindev}/${renderers}/NullRenderer.hpp
    PRIVATE ${maindev}/${renderers}/BoardRenderer.hpp
    PRIVATE ${maindev}/${renderers}/BoardRenderer.cpp
    PRIVATE ${maindev}/${services}/GuiService.hpp
    PRIVATE ${maindev}/${services}/GuiService.cpp
    PRIVATE ${maindev}/${go}/BoardConstants.hpp
    PRIVATE ${maindev}/${go}/BoardConstants.cpp
    PRIVATE ${maindev}/${go}/GoPoint.hpp
    PRIVATE ${maindev}/${go}/GoPoint.cpp
    PRIVATE ${maindev}/${go}/Size.hpp
    PRIVATE ${RESOURCES}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${main}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt5::Widgets
)

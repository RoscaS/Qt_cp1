cmake_minimum_required(VERSION 3.12)
project(03_prepa_tests)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(
    SOURCE_FILES
    main.cpp

        Exemples/00_Table/table.cpp
        Exemples/00_Table/table.h

        Serie03_Inputs/Radio_01/s03e01.cpp
        Serie03_Inputs/Radio_01/s03e01.h
        Serie03_Inputs/Radio_02/s03e02.cpp
        Serie03_Inputs/Radio_02/s03e02.h
        Serie03_Inputs/Radio_03/s03e03.cpp
        Serie03_Inputs/Radio_03/s03e03.h
        Serie03_Inputs/Radio_04/s03e04.cpp
        Serie03_Inputs/Radio_04/s03e04.h

        Serie04_Lists/Lists_01/s04e01.cpp
        Serie04_Lists/Lists_01/s04e01.h
        Serie04_Lists/Lists_02/s04e02.cpp
        Serie04_Lists/Lists_02/s04e02.h
        Serie04_Lists/Lists_03/s04e03.cpp
        Serie04_Lists/Lists_03/s04e03.h
        Serie04_Lists/Lists_04/s04e04.cpp
        Serie04_Lists/Lists_04/s04e04.h

        Serie05_WrapUp/WrapUp_01_Convert/convert.cpp
        Serie05_WrapUp/WrapUp_01_Convert/convert.h
        Serie05_WrapUp/WrapUp_02_Chrono/chrono.cpp
        Serie05_WrapUp/WrapUp_02_Chrono/chrono.h

        Serie06_Paint/Paint_01/s06e01.cpp
        Serie06_Paint/Paint_01/s06e01.h
        Serie06_Paint/Paint_02/s06e02.cpp
        Serie06_Paint/Paint_02/s06e02.h
        Serie06_Paint/Paint_03/s06e03.cpp
        Serie06_Paint/Paint_03/s06e03.h

        Serie07_GraphicsView/GraphicsV_01/s07e01.cpp
        Serie07_GraphicsView/GraphicsV_01/s07e01.h
        Serie07_GraphicsView/GraphicsV_02/s07e02.cpp
        Serie07_GraphicsView/GraphicsV_02/s07e02.h

        Serie09_Coords/Coords_01/s09e01.cpp
        Serie09_Coords/Coords_01/s09e01.h
        )


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)


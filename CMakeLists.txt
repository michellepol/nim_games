cmake_minimum_required(VERSION 3.5)

project(Number_methods LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(SOURCE
        source/main.cpp
        source/mainwindow.cpp
        source/heap.cpp
        source/bucket.cpp
        source/rock.cpp
        source/menuwindow.cpp
        source/gamewindow.cpp
        source/ruleswindow.cpp
        source/winnerwindow.cpp
        source/ai.cpp
        resources.qrc
)

set(HEADERS
        headers/mainwindow.h
        headers/heap.h
        headers/bucket.h
        headers/rock.h
        headers/menuwindow.h
        headers/gamewindow.h
        headers/ruleswindow.h
        headers/winnerwindow.h
        headers/ai.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Number_methods
        ${SOURCE} ${HEADERS} )
else()
    if(ANDROID)
        add_library(Number_methods SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Number_methods ${SOURCE} ${HEADERS})
    endif()
endif()

target_link_libraries(Number_methods PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# // ------------------------------------------------------------------------------
#
# This is CMake-Project for "QFileTest" GUI Utility-Application.
#
# License: see "LICENSE" file.
# Tools: QT, GCC || CLang
# API: C/C++.
# Platforms: Any with C++ & QT.
# 
# // ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.5 FATAL_ERROR ) # QT5 + CMake required 3.5 minimum.

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "qfiletest" )

# Project Version
set ( PROJECT_VERSION 0.0.1 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# C++ Version
set ( CMAKE_CXX_STANDARD 11 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# =================================================================================
# CONFIGS
# =================================================================================

# Prefix to headers & sources dir.
set ( PROJECT_SRC_DIR_PREFIX "src/cxx/" )

# =================================================================================
# QT Libraries/Modules
# =================================================================================

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Core Quick Qml QuickControls2 Widgets LinguistTools Xml REQUIRED)

# =================================================================================
# HEADERS
# =================================================================================

set ( QFILETEST_HEADERS
	"${PROJECT_SRC_DIR_PREFIX}MainWindow.hpp"
        "mainwindow.ui" )

# =================================================================================
# SOURCES
# =================================================================================

set ( QFILETEST_SOURCES
	"${PROJECT_SRC_DIR_PREFIX}main.cpp"
	"${PROJECT_SRC_DIR_PREFIX}MainWindow.cpp")
	
# =================================================================================
# RESOURCES
# =================================================================================

# Localizations
set(TS_FILES qfiletest_en_US.ts)

# =================================================================================
# BUILD
# =================================================================================

# Platform
if ( ANDROID ) # Android

	# Add SHARED Library for Android
        add_library ( qfiletest SHARED ${QFILETEST_SOURCES} ${QFILETEST_HEADERS} ${TS_FILES} )

else ( ANDROID ) # Desktop (Mac, Windows, Linux)

	# Add Executable-Object
        add_executable ( qfiletest ${QFILETEST_SOURCES} ${QFILETEST_HEADERS} ${TS_FILES} )
	
	# Configure Executable Object
	set_target_properties ( qfiletest PROPERTIES
		OUTPUT_NAME "QFileTest"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}" )
	
endif ( ANDROID )

#if(ANDROID)
#  add_library(qfiletest SHARED
#    main.cpp
#    mainwindow.cpp
#    mainwindow.hpp
#    mainwindow.ui
#    ${TS_FILES}
#  )
#else()
#  add_executable(qfiletest
#    main.cpp
#    mainwindow.cpp
#    mainwindow.hpp
#    mainwindow.ui
#    ${TS_FILES}
#  )
#endif()

# Link
target_link_libraries( qfiletest PRIVATE Qt5::Core Qt5::Quick Qt5::QuickControls2 Qt5::Qml Qt5::Widgets Qt5::Xml )

# Translation
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

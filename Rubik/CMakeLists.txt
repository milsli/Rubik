


cmake_minimum_required(VERSION 3.24.2)
project(Rubik VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt6  REQUIRED COMPONENTS  Core Gui Quick Quick3D)


qt_standard_project_setup()

qt_add_executable(Rubik
    main.cpp
)

set_target_properties(Rubik PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(Rubik PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appRubik
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_add_qml_module(Rubik
    URI RubikSideModule
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES rubikside.h rubikside.cpp
    RESOURCES qt_logo.png
    RESOURCE_PREFIX "/qt/qml"
    IMPORTS
        QtQuick3D
)

target_link_libraries(Rubik
    PRIVATE Qt6::Core Qt6::Gui Qt6::Quick Qt6::Quick3D
)

include(GNUInstallDirs)
install(TARGETS Rubik
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

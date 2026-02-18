cmake_minimum_required(VERSION 3.16)

project(canvaspainter_helloworld VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick CanvasPainter)

qt_policy(SET QTP0001 NEW)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appcanvaspainter_helloworld
    main.cpp
)

qt_add_qml_module(appcanvaspainter_helloworld
    URI canvaspainter_helloworld
    QML_FILES
        Main.qml
    SOURCES
        helloitem.h
        helloitem.cpp
        helloitemrenderer.h
        helloitemrenderer.cpp
    RESOURCES
        qt-translucent.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appcanvaspainter_helloworld PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appcanvaspainter_helloworld
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcanvaspainter_helloworld
    PRIVATE Qt6::Quick Qt6::CanvasPainter
)

include(GNUInstallDirs)
install(TARGETS appcanvaspainter_helloworld
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

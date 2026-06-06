cmake_minimum_required(VERSION 3.19)
project(TabMenu LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Pdf PdfWidgets)

qt_standard_project_setup()

qt_add_executable(TabMenu
    WIN32 MACOSX_BUNDLE
        src/main.cpp
        src/ui/mainwindow.cpp
        src/ui/mainwindow.h
        src/ui/mainwindow.ui
        src/resources/resources.qrc
        src/core/DocumentManager.cpp
        src/core/DocumentManager.h
        src/ui/PdfViewerWidget.cpp
        src/ui/PdfViewerWidget.h
)

target_link_libraries(TabMenu
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Pdf
        Qt::PdfWidgets
)

install(TARGETS TabMenu
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET TabMenu
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

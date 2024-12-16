cmake_minimum_required(VERSION 3.5)

project(src VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_subdirectory(libs/QCustomPlot-library-2.1.1.1)

set(PROJECT_SOURCES
    s21_linked_list.c
    s21_calc.h
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

include_directories(libs)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(src
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        s21_validator.c
        s21_polish_notation.c
        s21_calc.c
        s21_graph.h s21_graph.cpp s21_graph.ui
        s21_credit.c s21_deposit.c
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET src APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(src SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(src
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(src PRIVATE Qt${QT_VERSION_MAJOR}::Widgets qcustomplot)
target_compile_definitions(src PRIVATE QCUSTOMPLOT_USE_LIBRARY)

find_package(Qt6 REQUIRED COMPONENTS PrintSupport)
target_link_libraries(src PRIVATE Qt6::PrintSupport)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.src)
endif()
set_target_properties(src PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS src
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(src)
endif()

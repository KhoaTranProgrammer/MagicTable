cmake_minimum_required(VERSION 3.16)

project(FullMatchChess VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../build/lib/)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appFullMatchChess
    main.cpp
)

qt_add_qml_module(appFullMatchChess
    URI FullMatchChess
    VERSION 1.0
    QML_FILES
        Main.qml
        MovingStep.qml
        Background.qml
    RESOURCES
        "icon/logo.png"
        "icon/table.png"
        "icon/Blunder.png"
        "icon/Good.png"
        "icon/Inaccuracy.png"
        "icon/Mistake.png"
        "icon/Neutral.png"
        "icon/sparkleSize.png"
        "icon/star.png"
        "icon/draw.png"
        "icon/winner.png"
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appFullMatchChess PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appFullMatchChess
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFullMatchChess
    PRIVATE Qt6::Quick Qt6::Multimedia
)

include(GNUInstallDirs)
install(TARGETS appFullMatchChess
    BUNDLE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
    LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
    RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../../build/lib/)

set_target_properties(appFullMatchChess PROPERTIES
    QT_ANDROID_EXTRA_LIBS
    "${CMAKE_CURRENT_LIST_DIR}/../../build/lib/MT_Chess_QML/libMT_Chess_QML_arm64-v8a.so;${CMAKE_CURRENT_LIST_DIR}/../../build/lib/libMT_Core_arm64-v8a.so;${CMAKE_CURRENT_LIST_DIR}/../../build/lib/libMT_Chess_arm64-v8a.so"
)

set_target_properties(appFullMatchChess PROPERTIES
    QT_ANDROID_EXTRA_PLUGINS
    "${CMAKE_CURRENT_LIST_DIR}/../../build/lib/MT_Chess_QML/"
)

set_target_properties(appFullMatchChess PROPERTIES
    QT_ANDROID_PACKAGE_SOURCE_DIR
    "${CMAKE_CURRENT_LIST_DIR}/android"
)

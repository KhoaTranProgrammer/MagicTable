cmake_minimum_required(VERSION 3.16)

project(MT_ChessQMLApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../build/lib/)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appMT_ChessQMLApp
    main.cpp
)

qt_add_qml_module(appMT_ChessQMLApp
    URI MT_ChessQMLApp
    VERSION 1.0
    QML_FILES
        Main.qml
        Background.qml
        MovingStep.qml
    RESOURCES
        "icon/table.png"
        "res/chess-hitting.wav"
        "res/start_game.wav"
        "res/end_game.wav"
        "res/LegendofOne.wav"
        "icon/sparkleSize.png"
        "icon/star.png"
        "icon/logo.png"
        "android/AndroidManifest.xml"
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMT_ChessQMLApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMT_ChessQMLApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMT_ChessQMLApp
    PRIVATE Qt6::Quick Qt6::Multimedia
)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../../build/lib/MT_DSA_QML)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../../build/lib/)

include(GNUInstallDirs)
install(TARGETS appMT_ChessQMLApp
    BUNDLE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
    LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
    RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
)

set_target_properties(appMT_ChessQMLApp PROPERTIES
    QT_ANDROID_EXTRA_LIBS
    "${CMAKE_CURRENT_LIST_DIR}/../../build/lib/MT_Chess_QML/libMT_Chess_QML_arm64-v8a.so;${CMAKE_CURRENT_LIST_DIR}/../../build/lib/libMT_Core_arm64-v8a.so;${CMAKE_CURRENT_LIST_DIR}/../../build/lib/libMT_Chess_arm64-v8a.so"
)

set_target_properties(appMT_ChessQMLApp PROPERTIES
    QT_ANDROID_EXTRA_PLUGINS
    "${CMAKE_CURRENT_LIST_DIR}/../../build/lib/MT_Chess_QML/"
)

set_target_properties(appMT_ChessQMLApp PROPERTIES
    QT_ANDROID_PACKAGE_SOURCE_DIR
    "${CMAKE_CURRENT_LIST_DIR}/android"
)


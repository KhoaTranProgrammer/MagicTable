cmake_minimum_required(VERSION 3.16)

project(SpeedChessApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../build/lib/)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appSpeedChessApp
    main.cpp
)

qt_add_qml_module(appSpeedChessApp
    URI SpeedChessApp
    VERSION 1.0
    QML_FILES
        Main.qml
        Background.qml
    RESOURCES
        "icon/table.png"
        "icon/sparkleSize.png"
        "icon/star.png"
        "icon/logo.png"
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appSpeedChessApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSpeedChessApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSpeedChessApp
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appSpeedChessApp
    BUNDLE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
    LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
    RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../build/lib
)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../../build/lib/)


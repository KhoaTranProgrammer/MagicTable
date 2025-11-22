CONFIG -= qt

TEMPLATE = lib
DEFINES += MT_CHESS_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MT_Chess.cpp \
    MT_Chess_Object.cpp \
    MT_KingChess.cpp

HEADERS += \
    MT_Chess.h \
    MT_Chess_Object.h \
    MT_KingChess.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

# Rules for deployment.
win32 {
    targetHeader.path += $$PWD/../../build/include
    targetHeader.files += $$PWD/*.h
    INSTALLS += targetHeader

    targetLibrary.path += $$PWD/../../build/lib
    CONFIG(debug, debug|release):targetLibrary.files += $$OUT_PWD/debug/*.dll
    CONFIG(release, debug|release):targetLibrary.files += $$OUT_PWD/release/*.dll
    INSTALLS += targetLibrary

    INCLUDEPATH += $$PWD/../../build/include
    DEPENDPATH += $$PWD/../../build/include
    LIBS += -L$$PWD/../../build/lib -lMT_Core
}

android {
    # Copy the header to the folder as the plugin binary
    targetHeader.path += $$PWD/../../build/include
    targetHeader.files += $$PWD/*.h
    INSTALLS += targetHeader

    CONFIG(debug, debug|release):targetLibrary.files += $$OUT_PWD/*.so
    targetLibrary.path += $$PWD/../../build/lib
    INSTALLS += targetLibrary

    INCLUDEPATH += $$PWD/../../build/include
    DEPENDPATH += $$PWD/../../build/include
    LIBS += -L$$PWD/../../build/lib -lMT_Core_arm64-v8a
}

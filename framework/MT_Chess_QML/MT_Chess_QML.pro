TEMPLATE = lib
TARGET = MT_Chess_QML
QT += qml quick network
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.mycompany.qmlcomponents

DESTDIR = $$PWD/../../build/lib/MT_Chess_QML

# Input
SOURCES += \
        MT_Chess_QML.cpp \
        MT_Chess_QMLEvalObject.cpp \
        MT_Chess_QMLPlugin.cpp \
        MT_Chess_QMLObject.cpp \
        MT_Chess_QMLPositionObject.cpp \
        MT_KingChess_QML.cpp

HEADERS += \
        MT_Chess_QML.h \
        MT_Chess_QMLEvalObject.h \
        MT_Chess_QMLPlugin.h \
        MT_Chess_QMLObject.h \
        MT_Chess_QMLPositionObject.h \
        MT_KingChess_QML.h

DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

# Copy the qmldir file to the same folder as the plugin binary
cpqmldir.files = qmldir
win32 {
    cpqmldir.path = $$PWD/../../build/lib/MT_Chess_QML
}
android {
    cpqmldir.path = $$[QT_INSTALL_QML]/MT_Chess_QML
}
COPIES += cpqmldir

win32 {
    targetHeader.path += $$PWD/../../build/include
    targetHeader.files += $$PWD/*.h
    INSTALLS += targetHeader

    targetLibrary.path += $$PWD/../../build/lib/MT_Chess_QML
    CONFIG(debug, debug|release):targetLibrary.files += $$OUT_PWD/debug/*.dll
    CONFIG(release, debug|release):targetLibrary.files += $$OUT_PWD/release/*.dll
    INSTALLS += targetLibrary
}

android {
    CONFIG(debug, debug|release): targetLibrary.files += $$OUT_PWD/*.so
    targetLibrary.path += "D:/Qt/6.9.3/android_arm64_v8a/qml/MT_Chess_QML"
    INSTALLS += targetLibrary
}

win32 {
    INCLUDEPATH += $$PWD/../../build/include
    DEPENDPATH += $$PWD/../../build/include
    LIBS += -L$$PWD/../../build/lib -lMT_Core -lMT_Chess
}

android {
    INCLUDEPATH += $$PWD/../../build/include
    DEPENDPATH += $$PWD/../../build/include
    LIBS += -L$$PWD/../../build/lib -lMT_Core_arm64-v8a -lMT_Chess_arm64-v8a
}

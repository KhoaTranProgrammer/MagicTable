#*
#* MIT License
#/*
# * Copyright (c) 2022 KhoaTran Programmer
# *
# * Permission is hereby granted, free of charge, to any person obtaining a copy
# * of this software and associated documentation files (the "Software"), to deal
# * in the Software without restriction, including without limitation the rights
# * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# * copies of the Software, and to permit persons to whom the Software is
# * furnished to do so, subject to the following conditions:
# *
# * The above copyright notice and this permission notice shall be included in all
# * copies or substantial portions of the Software.
# *
# * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# * SOFTWARE.
# */

#/********************************************************************
# * PURPOSE                                                          *
# ********************************************************************
# * This is configuration file for build in Qt qmake                 *
# *******************************************************************/

TEMPLATE = lib
TARGET = MT_DSA_QML
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.mtdsa.mtdsaqml

win32 {
    DESTDIR = $$PWD/../../build/lib/MT_DSA_QML
}

# Input
SOURCES += \
        MT_DSA_QMLLineObject.cpp \
        MT_DSA_QMLList.cpp \
        MT_DSA_QMLListObject.cpp \
        MT_DSA_QMLObject.cpp \
        MT_DSA_QML.cpp \
        MT_DSA_QMLPlugin.cpp \
        MT_DSA_QMLTree.cpp \
        MT_DSA_QMLTreeObject.cpp

HEADERS += \
        MT_DSA_QMLLineObject.h \
        MT_DSA_QMLList.h \
        MT_DSA_QMLListObject.h \
        MT_DSA_QMLObject.h \
        MT_DSA_QML.h \
        MT_DSA_QMLPlugin.h \
        MT_DSA_QMLTree.h \
        MT_DSA_QMLTreeObject.h

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
    cpqmldir.path = $$PWD/../../build/lib/MT_DSA_QML
}
COPIES += cpqmldir

INCLUDEPATH += $$PWD/../../build/include
DEPENDPATH += $$PWD/../../build/include
LIBS += -L$$PWD/../../build/lib -lMT_Core -lMT_DSA

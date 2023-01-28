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

QT -= gui

TEMPLATE = lib
DEFINES += MT_CORE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MT_Atom.cpp \
    MT_Object.cpp \
    MT_Position.cpp \
    MT_RefObject.cpp \
    MT_Table.cpp

HEADERS += \
    MT_Atom.h \
    MT_Object.h \
    MT_Position.h \
    MT_RefObject.h \
    MT_Table.h \
    MT_Types.h

# Rules for deployment.
win32 {
    targetHeader.path += $$PWD/../../build/include
    targetHeader.files += $$PWD/*.h
    INSTALLS += targetHeader

    targetLibrary.path += $$PWD/../../build/lib
    CONFIG(debug, debug|release):targetLibrary.files += $$OUT_PWD/debug/*.dll
    CONFIG(release, debug|release):targetLibrary.files += $$OUT_PWD/release/*.dll
    INSTALLS += targetLibrary
}

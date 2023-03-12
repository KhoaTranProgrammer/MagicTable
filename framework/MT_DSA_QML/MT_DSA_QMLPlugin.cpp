/*
 * MIT License
 *
 * Copyright (c) 2022 KhoaTran Programmer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/********************************************************************
 * PURPOSE                                                          *
 ********************************************************************
 * This is QML plugin used by QML application for Data Structure    *
 * and Algorithm                                                    *
 *******************************************************************/

#include "MT_DSA_QMLPlugin.h"

#include "MT_DSA_QML.h"
#include "MT_DSA_QMLTree.h"
#include "MT_DSA_QMLLineObject.h"

#include <qqml.h>

void MT_DSA_QMLPlugin::registerTypes(const char *uri)
{
    // @uri com.mtdsa.mtdsaqml
    qmlRegisterType<MT_DSA_QML>(uri, 1, 0, "MT_DSA_QML");
    qmlRegisterType<MT_DSA_QMLTree>(uri, 1, 0, "MT_DSA_QMLTree");
    qmlRegisterType<MT_DSA_QMLLineObject>(uri, 1, 0, "MT_DSA_QMLLineObject");
}


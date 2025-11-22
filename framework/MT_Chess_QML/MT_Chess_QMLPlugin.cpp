#include "MT_Chess_QMLPlugin.h"

#include "MT_Chess_QML.h"

#include <qqml.h>

void MT_Chess_QMLPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<MT_Chess_QML>(uri, 1, 0, "MT_Chess_QML");
}

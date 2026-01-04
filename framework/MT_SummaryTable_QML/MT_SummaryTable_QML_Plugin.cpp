#include "MT_SummaryTable_QML_Plugin.h"

#include "MT_SummaryTable_QML.h"

#include <qqml.h>

void MT_SummaryTable_QMLPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<MT_SummaryTable_QML>(uri, 1, 0, "MT_SummaryTable_QML");
}

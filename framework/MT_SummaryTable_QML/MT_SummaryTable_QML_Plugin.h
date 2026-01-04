#ifndef MT_SUMMARYTABLE_QML_PLUGIN_H
#define MT_SUMMARYTABLE_QML_PLUGIN_H

#include <QQmlExtensionPlugin>

class MT_SummaryTable_QMLPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // MT_SUMMARYTABLE_QML_PLUGIN_H

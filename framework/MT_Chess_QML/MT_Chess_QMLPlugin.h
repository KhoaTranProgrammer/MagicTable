#ifndef MT_CHESSQML_PLUGIN_H
#define MT_CHESSQML_PLUGIN_H

#include <QQmlExtensionPlugin>

class MT_Chess_QMLPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // MT_CHESSQML_PLUGIN_H

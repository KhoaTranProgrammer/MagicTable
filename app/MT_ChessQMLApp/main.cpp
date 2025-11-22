#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QScreenCapture>
#include <QMediaRecorder>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MT_ChessQMLApp", "Main");

    return app.exec();
}

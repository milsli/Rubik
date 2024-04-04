#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick3D/qquick3d.h>


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

    engine.loadFromModule("RubikSideModule", "Main");

    return app.exec();
}

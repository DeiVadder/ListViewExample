#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <QVariant>
#include "noteentry.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QList<QObject*> listModel;
    listModel.append(new NoteEntry("Amy", 25, false));
    listModel.append(new NoteEntry("Bert", 87, true));
    listModel.append(new NoteEntry("Carl", 15, false));
    listModel.append(new NoteEntry("Donald", 55, false));


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    engine.rootContext()->setContextProperty("DeathList",QVariant::fromValue(listModel));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Modules dirs.
    QStringList libPaths = QCoreApplication::libraryPaths();

    // Add application custom paths.
    libPaths.append(".");
    libPaths.append("imageformats");
    libPaths.append("platforms");
    libPaths.append("plugins");
    QCoreApplication::setLibraryPaths( libPaths );

    //
    //const QString rootDir = QCoreApplication::applicationDirPath();

    // Set Organization Name
    QCoreApplication::setOrganizationName( "C0DE4UN INC." );

    // Set Application Name
    QCoreApplication::setApplicationName( "QFileTest" );

    // Set Version
    QCoreApplication::setApplicationVersion( "1.0" );

    QGuiApplication app(argc, argv);

    //
    //app.addLibraryPath( rootDir );
    //QCoreApplication::addLibraryPath( rootDir );

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

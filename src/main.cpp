#include <QCommandLineParser>
#include <QCoreApplication>

#include "config.h"

void initCommandLineParser(const QCoreApplication &application)
{
    QCommandLineParser parser;
    parser.setApplicationDescription(QObject::tr("Terminal media player"));
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption inputOption(QStringList() << "i"
                                                 << "input",
                                   QObject::tr("Input to the tool"));
    parser.addOption(inputOption);
    parser.process(application);
}

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VER);

    initCommandLineParser(app);

    return QCoreApplication::exec();
}

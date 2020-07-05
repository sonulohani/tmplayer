/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include <QCoreApplication>

#include "CommandLineParser.h"
#include "FileInfoManager.h"
#include "config.h"

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VER);

    auto parser{tmplayer::CommandLineParser::instance()};
    tmplayer::CommandLineParser::resetInstance();

    return QCoreApplication::exec();
}

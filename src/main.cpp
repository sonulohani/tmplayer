/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "CommandLineParser.h"
#include "FileInfoManager.h"
#include "config.h"

#include <QCoreApplication>

using tmplayer::CommandLineParser;
using tmplayer::FileInfoManager;

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VER);

    auto commandLineParser{CommandLineParser::instance()};

    auto fileInfoManager{FileInfoManager::instance()};
    fileInfoManager->add(commandLineParser->inputPath());

    // Deallocating all singletons
    FileInfoManager::resetInstance();
    CommandLineParser::resetInstance();

    return QCoreApplication::exec();
}

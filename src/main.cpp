/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "CommandInvoker.h"
#include "CommandLineParser.h"
#include "FileInfoManager.h"
#include "InputHandler.h"
#include "PauseCommand.h"
#include "PlayCommand.h"
#include "config.h"

#include <QCoreApplication>
#include <QScopedPointer>
#include <QSharedPointer>
#include <SFML/Audio/Music.hpp>

using tmplayer::CommandInvoker;
using tmplayer::CommandLineParser;
using tmplayer::FileInfoManager;
using tmplayer::InputHandler;
using tmplayer::PauseCommand;
using tmplayer::PlayCommand;

void registerCommands(QSharedPointer<CommandInvoker> &commandInvokerSPtr)
{
    QSharedPointer<sf::Music> musicSPtr = QSharedPointer<sf::Music>(new sf::Music);

    QSharedPointer<tmplayer::PlayCommand> playCommandSPtr =
        QSharedPointer<tmplayer::PlayCommand>(new tmplayer::PlayCommand(musicSPtr));

    QSharedPointer<tmplayer::PauseCommand> pauseCommandSPtr =
        QSharedPointer<tmplayer::PauseCommand>(new tmplayer::PauseCommand(musicSPtr));

    commandInvokerSPtr->registerCommand(CommandInvoker::CommandType::PLAY, playCommandSPtr);
    commandInvokerSPtr->registerCommand(CommandInvoker::CommandType::PAUSE, pauseCommandSPtr);
}

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VER);

    auto commandLineParser{CommandLineParser::instance()};

    auto fileInfoManager{FileInfoManager::instance()};
    fileInfoManager->add(commandLineParser->inputPath());

    auto commandInvokerSPtr = QSharedPointer<CommandInvoker>(new CommandInvoker);
    registerCommands(commandInvokerSPtr);

    QScopedPointer<InputHandler> inputHandler{new InputHandler(commandInvokerSPtr)};

    while (true)
    {
        auto input = inputHandler->takeInputAndProcess();
        if (input == "quit" || input == "q")
        {
            break;
        }
    }

    // Deallocating all singletons
    FileInfoManager::resetInstance();
    CommandLineParser::resetInstance();

    return QCoreApplication::exec();
}

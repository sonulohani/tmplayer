/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "AddFileCommand.h"
#include "CommandInvoker.h"
#include "CommandLineParser.h"
#include "InputHandler.h"
#include "MediaPlaylist.h"
#include "PauseCommand.h"
#include "PlayCommand.h"
#include "config.h"

#include <QCoreApplication>
#include <QMediaPlayer>
#include <QScopedPointer>
#include <QSharedPointer>

using tmplayer::AddFileCommand;
using tmplayer::CommandInvoker;
using tmplayer::CommandLineParser;
using tmplayer::InputHandler;
using tmplayer::MediaPlaylist;
using tmplayer::PauseCommand;
using tmplayer::PlayCommand;

void registerCommands(QSharedPointer<CommandInvoker> &commandInvokerSPtr)
{
    QSharedPointer<QMediaPlayer> mediaPlayerSPtr = QSharedPointer<QMediaPlayer>(new QMediaPlayer);

    QSharedPointer<tmplayer::PlayCommand> playCommandSPtr =
        QSharedPointer<tmplayer::PlayCommand>(new tmplayer::PlayCommand(mediaPlayerSPtr));

    QSharedPointer<tmplayer::PauseCommand> pauseCommandSPtr =
        QSharedPointer<tmplayer::PauseCommand>(new tmplayer::PauseCommand(mediaPlayerSPtr));

    QSharedPointer<tmplayer::AddFileCommand> addFileCommandSPtr =
        QSharedPointer<tmplayer::AddFileCommand>(new tmplayer::AddFileCommand());

    commandInvokerSPtr->registerCommand(CommandInvoker::CommandType::PLAY, playCommandSPtr);
    commandInvokerSPtr->registerCommand(CommandInvoker::CommandType::PAUSE, pauseCommandSPtr);
    commandInvokerSPtr->registerCommand(CommandInvoker::CommandType::ADD, addFileCommandSPtr);
}

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VER);

    auto commandLineParser{CommandLineParser::instance()};

    auto mediaPlaylist{MediaPlaylist::instance()};
    // fileInfoManager->add(commandLineParser->inputPath()); TODO

    auto commandInvokerSPtr = QSharedPointer<CommandInvoker>(new CommandInvoker);
    registerCommands(commandInvokerSPtr);

    QScopedPointer<InputHandler> inputHandler{new InputHandler(commandInvokerSPtr)};

    while (true)
    {
        inputHandler->takeInputAndProcess();
    }

    // Deallocating all singletons
    MediaPlaylist::resetInstance();
    CommandLineParser::resetInstance();

    return QCoreApplication::exec();
}

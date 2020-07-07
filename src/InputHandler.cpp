/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "InputHandler.h"
#include "CommandInvoker.h"
#include "PlayCommand.h"

#include <QTextStream>

namespace tmplayer
{

InputHandler *InputHandler::s_pInputHandler = nullptr;

const QVector<QString> InputHandler::s_kCommandVec = {"play", "pause", "help"};

InputHandler *InputHandler::instance()
{
    if (s_pInputHandler == nullptr)
    {
        s_pInputHandler = new InputHandler;
    } // namespace tmplayer
    return s_pInputHandler;
}

void InputHandler::resetInstance()
{
    if (s_pInputHandler == nullptr)
    {
        delete s_pInputHandler;
        s_pInputHandler = nullptr;
    }
}

void InputHandler::takeInputAndProcess(CommandInvokerSPtr &invokerSPtr)
{
    QTextStream stream(stdin);
    auto input = stream.readLine();
    invokerSPtr->invoke(input);
}

} // namespace tmplayer

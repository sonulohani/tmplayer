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

InputHandler::InputHandler(CommandInvokerSPtr &invokerSPtr) : m_invokerSPtr(invokerSPtr)
{
}

QString InputHandler::takeInputAndProcess()
{
    QTextStream stream(stdin);
    auto input = stream.readLine();
    m_invokerSPtr->invoke(input);
    return input;
}

} // namespace tmplayer

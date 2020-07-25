/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "InputHandler.h"
#include "CommandInvoker.h"
#include "PlayCommand.h"

#include <QDebug>
#include <QKeyEvent>
#include <QTextStream>

namespace tmplayer
{

InputHandler::InputHandler(CommandInvokerSPtr &invokerSPtr, QObject *parent)
    : m_invokerSPtr(invokerSPtr), QObject(parent)
{
}

void InputHandler::dispatch()
{
    QTextStream stream(stdin);
    QList<QVariant> dataList;
    auto input = stream.readLine().simplified();
    qDebug() << "Input is " << input;
    auto commandName = input.split(" ")[0];
    input = input.remove(QRegExp("^" + commandName)).simplified();
    auto inputs = input.split(",");
    for (auto &input : inputs)
    {
        dataList.append(QVariant(input.remove("\"").remove("'")));
    }
    m_invokerSPtr->invoke(commandName, QVariant(dataList));
    emit dispatched();
}

} // namespace tmplayer

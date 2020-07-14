/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "CommandInvoker.h"
#include "ICommand.h"

#include <QWeakPointer>

namespace tmplayer
{

const QHash<QString, CommandInvoker::CommandType> CommandInvoker::s_kCommandMap = {
    {"play", CommandInvoker::CommandType::PLAY},
    {"pause", CommandType::PAUSE},
    {"add", CommandType::ADD},
    {"shuffle", CommandType::SHUFFLE}};

void CommandInvoker::registerCommand(const CommandInvoker::CommandType type, const ICommandSPtr &commandSPtr)
{
    QWeakPointer commandWPtr = commandSPtr.toWeakRef();
    if (!commandWPtr.isNull())
    {
        m_typeToCommandMap[type] = commandWPtr.lock();
    }
}

auto CommandInvoker::invoke(const QString &commandStr, const QVariant &data) -> bool
{
    auto it = s_kCommandMap.find(commandStr);
    if (it != s_kCommandMap.end())
    {
        auto typeToCommandIt = m_typeToCommandMap.find(it.value());
        if (typeToCommandIt != m_typeToCommandMap.end())
        {
            auto commandWPtr = typeToCommandIt.value().toWeakRef();

            if (!commandWPtr.isNull())
            {
                commandWPtr.lock()->execute(data);
                return true;
            }
        }
    }
    return false;
}

} // namespace tmplayer

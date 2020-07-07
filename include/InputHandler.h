/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include <QHash>
#include <QSharedPointer>
#include <QString>
#include <QVector>
#include <QtGlobal>

namespace tmplayer
{

class CommandInvoker;
using CommandInvokerSPtr = QSharedPointer<CommandInvoker>;

class InputHandler
{
  public:
    InputHandler(CommandInvokerSPtr &invokerSPtr);
    virtual ~InputHandler() = default;
    QString takeInputAndProcess();

  private:
    CommandInvokerSPtr m_invokerSPtr;
};

} // namespace tmplayer

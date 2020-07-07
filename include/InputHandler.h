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
    Q_DISABLE_COPY_MOVE(InputHandler)

  public:
    static InputHandler *instance();
    static void resetInstance();

  private:
    InputHandler() = default;
    virtual ~InputHandler() = default;

    void takeInputAndProcess(CommandInvokerSPtr &invokerSPtr);

  private:
    static InputHandler *s_pInputHandler;
    static const QVector<QString> s_kCommandVec;
};

} // namespace tmplayer

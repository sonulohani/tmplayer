/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include <QHash>
#include <QObject>
#include <QSharedPointer>
#include <QString>
#include <QVector>
#include <QtGlobal>

namespace tmplayer
{

class CommandInvoker;
using CommandInvokerSPtr = QSharedPointer<CommandInvoker>;

class InputHandler : public QObject
{
    Q_OBJECT
  public:
    explicit InputHandler(CommandInvokerSPtr &invokerSPtr, QObject *parent = nullptr);
    virtual ~InputHandler() = default;
    void dispatch();

  signals:
    void dispatched();

  private:
    CommandInvokerSPtr m_invokerSPtr;
    QString m_inputStr;
};

} // namespace tmplayer

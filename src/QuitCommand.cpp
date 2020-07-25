/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "QuitCommand.h"

#include <QCoreApplication>

namespace tmplayer
{

QuitCommand::QuitCommand(QObject *parent) : ICommand(parent)
{
}

void QuitCommand::execute(const QVariant &)
{
    qApp->quit();
}

} // namespace tmplayer
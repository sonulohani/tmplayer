/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include "ICommand.h"

namespace tmplayer
{

class QuitCommand : public ICommand
{
    Q_OBJECT
  public:
    explicit QuitCommand(QObject *parent = nullptr);
    virtual ~QuitCommand() = default;
    void execute(const QVariant & /*unused*/) override;

  signals:
    void quit();
};

} // namespace tmplayer
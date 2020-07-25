/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include "ICommand.h"

#include <QString>

namespace tmplayer
{

class AddFileCommand : public ICommand
{
  public:
    explicit AddFileCommand(QObject *parent = nullptr);
    ~AddFileCommand() = default;
    void execute(const QVariant &variant) override;
};

} // namespace tmplayer

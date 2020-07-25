/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include "ICommand.h"

#include <QSharedPointer>

class QMediaPlayer;
using MediaPlayerSPtr = QSharedPointer<QMediaPlayer>;

namespace tmplayer
{

class ShuffleCommand : public ICommand
{
  public:
    explicit ShuffleCommand(QObject *parent = nullptr);
    ~ShuffleCommand() = default;
    void execute(const QVariant & /*unused*/) override;

  private:
    MediaPlayerSPtr m_mediaPlayerSPtr;
};

} // namespace tmplayer

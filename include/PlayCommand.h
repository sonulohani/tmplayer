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

class PlayCommand : public ICommand
{
  public:
    PlayCommand(const MediaPlayerSPtr &mediaPlayerSPtr);
    ~PlayCommand() = default;
    void execute(const QVariant &) override;

  private:
    MediaPlayerSPtr m_mediaPlayerSPtr;
};
} // namespace tmplayer

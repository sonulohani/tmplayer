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

class PauseCommand : public ICommand
{
  public:
    PauseCommand(const MediaPlayerSPtr &mediaPlayerSPtr);
    virtual ~PauseCommand() = default;
    void execute(const QVariant &) override;

  private:
    MediaPlayerSPtr m_mediaPlayerSPtr;
};

} // namespace tmplayer

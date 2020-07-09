/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "PauseCommand.h"

#include <QMediaPlayer>

namespace tmplayer
{

PauseCommand::PauseCommand(const MediaPlayerSPtr &mediaPlayerSPtr) : m_mediaPlayerSPtr(mediaPlayerSPtr)
{
}

void PauseCommand::execute(const QVariant &)
{
    QWeakPointer<MediaPlayerSPtr> mediaPlayerWPtr = m_mediaPlayerSPtr.toWeakRef();
    if (!mediaPlayerWPtr.isNull())
    {
        mediaPlayerWPtr.lock()->pause();
    }
}

} // namespace tmplayer

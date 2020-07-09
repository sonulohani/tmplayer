/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "PlayCommand.h"
#include "MediaPlaylist.h"

#include <QMediaPlayer>
#include <QWeakPointer>

namespace tmplayer
{

PlayCommand::PlayCommand(const MediaPlayerSPtr &mediaPlayerSPtr) : m_mediaPlayerSPtr(mediaPlayerSPtr)
{
}

void PlayCommand::execute(const QVariant &)
{
    auto mediaPlayerWPtr{m_mediaPlayerSPtr.toWeakRef()};
    if (!mediaPlayerWPtr.isNull())
    {
        auto mediaPlaylist{MediaPlaylist::instance()};
        mediaPlayerWPtr.lock()->setPlaylist(mediaPlaylist);
        mediaPlayerWPtr.lock()->play();
    }
}
} // namespace tmplayer

/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "MediaPlaylist.h"

#include <QDir>

namespace tmplayer
{
MediaPlaylist *MediaPlaylist::s_pMediaPlaylist = nullptr;

auto MediaPlaylist::instance() -> MediaPlaylist *
{
    if (s_pMediaPlaylist == nullptr)
    {
        s_pMediaPlaylist = new MediaPlaylist;
    }
    return s_pMediaPlaylist;
}

void MediaPlaylist::resetInstance()
{
    if (s_pMediaPlaylist != nullptr)
    {
        delete s_pMediaPlaylist;
        s_pMediaPlaylist = nullptr;
    }
}

void MediaPlaylist::add(const QString &path)
{
    QUrl url{QUrl::fromUserInput(QDir::fromNativeSeparators(path))};
    addMedia(url);
}

} // namespace tmplayer

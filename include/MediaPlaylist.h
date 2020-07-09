/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

// Qt includes
#include <QMediaPlaylist>
#include <QtGlobal>

namespace tmplayer
{

class MediaPlaylist : public QMediaPlaylist
{
    Q_DISABLE_COPY_MOVE(MediaPlaylist)

  public:
    static MediaPlaylist *instance();
    static void resetInstance();
    void add(const QString &path);

  private:
    MediaPlaylist() = default;
    ~MediaPlaylist() = default;

  private:
    static MediaPlaylist *s_pMediaPlaylist;
};

} // namespace tmplayer

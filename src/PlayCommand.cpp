/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "PlayCommand.h"
#include "FileInfoManager.h"

#include <QMediaPlayer>
#include <QWeakPointer>

namespace tmplayer
{

PlayCommand::PlayCommand(const MediaPlayerSPtr &mediaPlayerSPtr) : m_mediaPlayerSPtr(mediaPlayerSPtr)
{
}

void PlayCommand::execute(const QVariant &)
{
    QWeakPointer<MediaPlayerSPtr> mediaPlayerWPtr = m_mediaPlayerSPtr.toWeakRef();
    if (!mediaPlayerWPtr.isNull())
    {
        auto fileInfoManager = FileInfoManager::instance();
        if (fileInfoManager->hasNext())
        {
            auto file = FileInfoManager::instance()->next().absoluteFilePath();
            mediaPlayerWPtr.lock()->openFromFile(file.toStdString());
            mediaPlayerWPtr.lock()->play();
        }
    }
}
} // namespace tmplayer

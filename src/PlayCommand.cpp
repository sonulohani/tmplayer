/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "PlayCommand.h"

#include <QWeakPointer>

namespace tmplayer
{

PlayCommand::PlayCommand(QSharedPointer<sf::Music> &music) : ICommand(), m_musicSPtr(music)
{
}

void PlayCommand::execute()
{
    QWeakPointer<sf::Music> musicWPtr = m_musicSPtr.toWeakRef();
    if (!musicWPtr.isNull())
    {
        musicWPtr.lock()->play();
    }
}
} // namespace tmplayer

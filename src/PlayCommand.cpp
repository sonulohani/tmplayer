/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "PlayCommand.h"

#include <QWeakPointer>
#include <SFML/Audio/Music.hpp>

namespace tmplayer
{

PlayCommand::PlayCommand(const sf::MusicSPtr &musicSPtr) : m_musicSPtr(musicSPtr)
{
}

void PlayCommand::execute(const QVariant &)
{
    QWeakPointer<sf::Music> musicWPtr = m_musicSPtr.toWeakRef();
    if (!musicWPtr.isNull())
    {
        musicWPtr.lock()->play();
    }
}
} // namespace tmplayer

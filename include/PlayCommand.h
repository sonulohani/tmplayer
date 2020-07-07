/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include "ICommand.h"

#include <QSharedPointer>
#include <SFML/Audio/Music.hpp>

namespace sf
{

class Music;
using MusicSPtr = QSharedPointer<Music>;

} // namespace sf

namespace tmplayer
{

class PlayCommand : public ICommand
{
  public:
    PlayCommand(const sf::MusicSPtr &musicSPtr);
    ~PlayCommand() = default;
    void execute() override;

  private:
    sf::MusicSPtr m_musicSPtr;
};
} // namespace tmplayer

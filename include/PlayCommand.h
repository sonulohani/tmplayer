/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include "ICommand.h"

#include <QSharedPointer>
#include <SFML/Audio/Music.hpp>

namespace tmplayer
{
class PlayCommand : public ICommand
{
  public:
    PlayCommand(QSharedPointer<sf::Music> &music);
    ~PlayCommand() = default;
    void execute() override;

  private:
    QSharedPointer<sf::Music> m_musicSPtr;
};
} // namespace tmplayer

/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include "ICommand.h"

#include <QSharedPointer>

namespace sf
{

class Music;
using MusicSPtr = QSharedPointer<Music>;

} // namespace sf

namespace tmplayer
{

class PauseCommand : public ICommand
{
  public:
    PauseCommand(const sf::MusicSPtr &musicSPtr);
    virtual ~PauseCommand() = default;
    void execute(const QVariant &) override;

  private:
    sf::MusicSPtr m_musicSPtr;
};

} // namespace tmplayer

/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "ShuffleCommand.h"
#include "MediaPlaylist.h"

namespace tmplayer
{

void ShuffleCommand::execute(const QVariant &)
{
    MediaPlaylist::instance()->shuffle();
}

} // namespace tmplayer

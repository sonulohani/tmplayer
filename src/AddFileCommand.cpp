/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "AddFileCommand.h"
#include "MediaPlaylist.h"

namespace tmplayer
{

AddFileCommand::AddFileCommand(QObject *parent) : ICommand(parent)
{
}

void AddFileCommand::execute(const QVariant &variant)
{
    if (variant.isValid())
    {
        QList<QVariant> dataList = variant.toList();
        for (const auto &data : dataList)
        {
            MediaPlaylist::instance()->add(data.toString());
        }
    }
}

} // namespace tmplayer

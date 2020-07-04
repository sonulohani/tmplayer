/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

// Qt includes
#include <QFileInfo>
#include <QString>
#include <QStringList>
#include <QtGlobal>

namespace tmplayer
{

class FileInfoManager final
{
    Q_DISABLE_COPY_MOVE(FileInfoManager)

  public:
    static FileInfoManager *instance();

    void addMediaInfo(const QFileInfo &mediaInfo);
    void addMediaInfo(const QString &file);
    void addDirectory(const QString &dirName);

  private:
    FileInfoManager() = default;
    ~FileInfoManager() = default;

  private:
    static FileInfoManager *s_pFileInfoManagerInstance;
    QList<QFileInfo> m_fileInfos;
};

} // namespace tmplayer

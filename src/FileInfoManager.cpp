/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "FileInfoManager.h"
#include <QDir>
#include <QDirIterator>

namespace tmplayer
{
FileInfoManager *FileInfoManager::s_pFileInfoManagerInstance = nullptr;

FileInfoManager *FileInfoManager::instance()
{
    if (s_pFileInfoManagerInstance == nullptr)
        s_pFileInfoManagerInstance = new FileInfoManager;
    return s_pFileInfoManagerInstance;
}

void FileInfoManager::addMediaInfo(const QFileInfo &fileInfo)
{
    if (fileInfo.exists())
        m_fileInfos.append(fileInfo);
}

void FileInfoManager::addMediaInfo(const QString &file)
{
    auto fileInfo = QFileInfo{file};
    addMediaInfo(fileInfo);
}

void FileInfoManager::addDirectory(const QString &dirName)
{
    QDir dir(dirName);
    if (dir.exists())
    {
        QDirIterator it(dir.absolutePath(), QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext())
        {
            addMediaInfo(it.next());
        }
    }
}

} // namespace tmplayer

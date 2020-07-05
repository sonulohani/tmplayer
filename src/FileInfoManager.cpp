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

auto FileInfoManager::instance() -> FileInfoManager *
{
    if (s_pFileInfoManagerInstance == nullptr)
    {
        s_pFileInfoManagerInstance = new FileInfoManager;
    }
    return s_pFileInfoManagerInstance;
}

void FileInfoManager::addFile(const QString &file)
{
    auto fileInfo = QFileInfo{file};
    if (fileInfo.exists())
    {
        m_fileInfos.append(fileInfo);
    }
}

void FileInfoManager::addDirectory(const QString &dirName)
{
    QDir dir(dirName);
    if (dir.exists())
    {
        QDirIterator it(dir.absolutePath(), QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext())
        {
            addFile(it.next());
        }
    }
}

void FileInfoManager::resetInstance()
{
    if (s_pFileInfoManagerInstance != nullptr)
    {
        delete s_pFileInfoManagerInstance;
        s_pFileInfoManagerInstance = nullptr;
    }
}

void FileInfoManager::add(const QString &path)
{
    QFileInfo fileInfo{path};
    fileInfo.isDir() ? addDirectory(path) : addFile(path);
}

auto FileInfoManager::hasNext() const -> bool
{
    return m_fileInfosIt.hasNext();
}

auto FileInfoManager::hasPrev() const -> bool
{
    return m_fileInfosIt.hasPrevious();
}

auto FileInfoManager::next() -> QFileInfo
{
    if (!m_fileInfos.empty() && hasNext())
    {
        return m_fileInfosIt.next();
    }
    m_fileInfosIt.toFront();
    return next();
}

auto FileInfoManager::prev() -> QFileInfo
{
    if (!m_fileInfos.empty() && hasPrev())
    {
        return m_fileInfosIt.previous();
    }
    m_fileInfosIt.toBack();
    return prev();
}

} // namespace tmplayer

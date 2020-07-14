/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include <QCommandLineParser>
#include <QtGlobal>

namespace tmplayer
{

class CommandLineParser : public QCommandLineParser
{
    Q_DISABLE_COPY_MOVE(CommandLineParser)

  public:
    static CommandLineParser *instance();
    static void resetInstance();
    auto inputPath() const -> QString;
    auto loggingEnabled() const -> bool;

  private:
    CommandLineParser();
    ~CommandLineParser() = default;

  private:
    static CommandLineParser *m_pCommandLineParser;
    QCommandLineOption inputPathOption{QStringList() << "i"
                                                     << "input",
                                       QObject::tr("Input path to the tool."), QString()};
    QCommandLineOption enableLoggingOption{QStringList() << "l"
                                                         << "log",
                                           QObject::tr("Enable logging.")};
};

} // namespace tmplayer

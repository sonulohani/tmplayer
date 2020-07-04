/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "CommandLineParser.h"
#include <QDebug>

namespace tmplayer
{

 CommandLineParser::CommandLineParser()
{
     setApplicationDescription(QObject::tr("Terminal media player"));
     addHelpOption();
     addVersionOption();
     Q_ASSERT(addOption(inputOption));
     Q_ASSERT(addOption(enableLoggingOption));
     process(*qApp);
 }

CommandLineParser *CommandLineParser::m_pCommandLineParser = nullptr;

CommandLineParser *CommandLineParser::instance()
{
    if (m_pCommandLineParser == nullptr)
    {
        m_pCommandLineParser = new CommandLineParser;
    }
    return m_pCommandLineParser;
}

QString CommandLineParser::inputPath() const
{
    return isSet(inputOption) ? value(inputOption) : QString();
}

bool CommandLineParser::loggingEnabled() const
{
    return isSet(enableLoggingOption);
}

} // namespace tmplayer

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
    inputPathOption.setValueName("input");
    Q_ASSERT(addOption(inputPathOption));
    Q_ASSERT(addOption(enableLoggingOption));
    process(*qApp);
}

CommandLineParser *CommandLineParser::m_pCommandLineParser = nullptr;

auto CommandLineParser::instance() -> CommandLineParser *
{
    if (m_pCommandLineParser == nullptr)
    {
        m_pCommandLineParser = new CommandLineParser;
    }
    return m_pCommandLineParser;
}

void CommandLineParser::resetInstance()
{
    if (m_pCommandLineParser != nullptr)
    {
        delete m_pCommandLineParser;
        m_pCommandLineParser = nullptr;
    }
}

auto CommandLineParser::inputPath() const -> QString
{
    return isSet(inputPathOption) ? value(inputPathOption) : QString();
}

auto CommandLineParser::loggingEnabled() const -> bool
{
    return isSet(enableLoggingOption);
}

} // namespace tmplayer

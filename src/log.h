// Copyright 2023 Vincent Westenberg
// License: GNU AGPL, version 3 or later; http://www.gnu.org/licenses/agpl.html

#ifndef FROGCON_LOG_H
#define FROGCON_LOG_H

#include <functional>
#include <fmt/format.h>

namespace frogcon
{

    enum class LogLevel { Fatal, Error, Warn, Info, Debug, Trace };

    class Logger
    {

    public:

        typedef std::function<void(LogLevel, const std::string&)> LogCallback;

        void setLogCallback(LogCallback callback)
        {
            m_logCallback = callback;
        }

        void setQuiet(bool quiet)
        {
            m_quiet = quiet;
        }

        bool isQuiet()
        {
            return m_quiet;
        }

        void setLogLevel(LogLevel level)
        {
            m_level = level;
        }

        LogLevel getLogLevel()
        {
            return m_level;
        }

        template<typename S, typename... Args>
        void log(LogLevel level, const S& format, const Args&... args)
        {
            if (!m_quiet && level <= m_level)
            {
                m_logCallback(level, fmt::format(format, args...));
            }
        }

        template<typename S, typename... Args>
        void fatal(const S& format, const Args&... args)
        {
            log(LogLevel::Fatal, format, args...);
        }

        template<typename S, typename... Args>
        void error(const S& format, const Args&... args)
        {
            log(LogLevel::Error, format, args...);
        }

        template<typename S, typename... Args>
        void warn(const S& format, const Args&... args)
        {
            log(LogLevel::Warn, format, args...);
        }

        template<typename S, typename... Args>
        void info(const S& format, const Args&... args)
        {
            log(LogLevel::Info, format, args...);
        }

        template<typename S, typename... Args>
        void debug(const S& format, const Args&... args)
        {
            log(LogLevel::Debug, format, args...);
        }

        template<typename S, typename... Args>
        void trace(const S& format, const Args&... args)
        {
            log(LogLevel::Trace, format, args...);
        }

    private:

        LogCallback m_logCallback {[](LogLevel, const std::string&) {}};

        bool m_quiet {false};

        LogLevel m_level {LogLevel::Trace};

    };

}

#endif // FROGCON_LOG_H

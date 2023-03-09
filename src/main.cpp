// Copyright 2023 Vincent Westenberg
// License: GNU AGPL, version 3 or later; http://www.gnu.org/licenses/agpl.html

#include <ctime>
#include <iostream>
#include <map>
#include <fmt/chrono.h>
#include "log.h"
#include "webservice.h"

int main()
{
    frogcon::Logger logger;

    logger.setLogCallback([](frogcon::LogLevel level, const std::string& message) {
        static const std::map<frogcon::LogLevel, std::string> tag = {
            {frogcon::LogLevel::Fatal, "FATAL"},
            {frogcon::LogLevel::Error, "ERROR"},
            {frogcon::LogLevel::Warn, "WARN"},
            {frogcon::LogLevel::Info, "INFO"},
            {frogcon::LogLevel::Debug, "DEBUG"},
            {frogcon::LogLevel::Trace, "TRACE"}
        };

        auto time = std::time(nullptr);
        auto tm = *localtime(&time);

        fmt::print("{:%Y-%m-%d %H:%M:%S} [{}] {}\n", tm, tag.at(level), message);
    });

    logger.fatal("{} smash.", "Helga");
    logger.error("Nope.");
    logger.warn("Not good.");
    logger.info("Server burns.");
    logger.debug("Blubber.");
    logger.trace("Fish.");

    frogcon::WebService webService;
    webService.run("localhost", 8000);

    return 0;
}

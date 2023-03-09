// Copyright 2023 Vincent Westenberg
// License: GNU AGPL, version 3 or later; http://www.gnu.org/licenses/agpl.html

#include <stdexcept>
#include <sys/types.h>
#include <sys/socket.h>
#include "webservice.h"

void frogcon::WebService::run(const std::string& address, int port)
{
    m_server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (m_server_sockfd < 0)
    {
        throw std::runtime_error("socket creation failed");
    }
}

// Copyright 2023 Vincent Westenberg
// License: GNU AGPL, version 3 or later; http://www.gnu.org/licenses/agpl.html

#ifndef FROGCON_WEBSERVICE_H
#define FROGCON_WEBSERVICE_H

#include <string>

namespace frogcon
{

    class WebService
    {

    public:

        void run(const std::string& address, int port);

    private:

        int m_server_sockfd;

    };

}

#endif // FROGCON_WEBSERVICE_H

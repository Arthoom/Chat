#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Client/Client.h"
#include "Server/Server.h"

int main()
{
	std::cout << "listen? (y/n)\n";
	char c;
	std::cin >> c;
	std::cout << "port: \n";
	unsigned short port;
	std::cin >> port;

	if(c == 'y')
	{
		Server server(port);
		server.serverLoop();
	}
	else
	{
		Client client("puchalski.pro", port, "test");
		client.join();
	}

	return 0;
}

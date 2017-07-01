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
	std::cout << "\nport:\n";
	int port;
	std::cin >> port;

	if(c == 'y')
	{
		Server server(port);
		server.serverLoop();
	}
	else
	{
		Client client("puchalski.pro", 35353, "test");
		client.join();
	}

	return 0;
}

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Client/Client.h"

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
		sf::TcpSocket socket;

		sf::TcpListener listener;
		if (listener.listen(port) != sf::Socket::Done)
			return std::cout << "xd\n", 0;
		std::cout << "listener listening on port\n";
		if (listener.accept(socket) != sf::Socket::Done)
			return std::cout << "xd\n", 0;
		std::cout << "listener accepted socket\n";

		sf::Packet packet;
		while(socket.receive(packet) == sf::Socket::Done)
		{
			std::cout << "socket received packet\n";
			int32_t x;
			packet >> x;
			std::cout << "received id " << x << "\n";
		}
	}
	else
	{
		Client client("puchalski.pro", 35353, "test");
		client.join();
	}

	return 0;
}

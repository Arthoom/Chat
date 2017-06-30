#include "ClientListener.h"
#include <iostream>

ClientListener::ClientListener(SocketWrapper &s) : socket_wrapper(s) {}

void ClientListener::operator()()
{
	sf::Packet packet;
	while(socket_wrapper.getSocket().receive(packet) == sf::Socket::Done)
	{
		std::string nick, message;
		packet >> nick >> message;
		std::cout << nick << ": " << message << std::endl;
	}
}

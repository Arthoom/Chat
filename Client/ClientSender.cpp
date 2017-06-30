#include "ClientSender.h"
#include <iostream>

ClientSender::ClientSender(SocketWrapper &s, std::string n) : socket_wrapper(s), nick(n) {}

void ClientSender::operator()()
{
	std::string message;
	while(true)
	{
		std::cin >> message;
		socket_wrapper.lock();
		sf::Packet packet;
		packet << nick << message;
		socket_wrapper.getSocket().send(packet);
		socket_wrapper.unlock();
	}
}

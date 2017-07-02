#include "ClientSender.h"

ClientSender::ClientSender(SocketWrapper &s, std::string n) : socket_wrapper(s), nick(n) {}

void ClientSender::operator()()
{
	std::string message;
	while(true)
	{
		std::cin >> message;
		sf::Packet packet;
		packet << nick << message;
		socket_wrapper.lock();
		socket_wrapper.getSocket().send(packet);
		socket_wrapper.unlock();
	}
}

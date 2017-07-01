#include "ServerListener.h"

ServerListener::ServerListener(SocketWrapper &s, Server &serv) : socket_wrapper(s), server(serv) {}

bool ServerListener::isShutDown() { return shut_down; }

void ServerListener::operator()()
{
	sf::Packet packet;
	while(socket_wrapper.getSocket().receive(packet) == sf::Socket::Done)
		server.sendAll(packet);

	shut_down = true;
}

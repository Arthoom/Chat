#include "ServerSender.h"

ServerSender::ServerSender(SocketWrapper &s) : socket_wrapper(s) {}

void ServerSender::send(sf::Packet packet)
{
	socket_wrapper.lock();
	socket_wrapper.getSocket().send(packet);
	socket_wrapper.unlock();
}

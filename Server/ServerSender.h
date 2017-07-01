#pragma once
#include "../SocketWrapper.h"

class ServerSender
{
public:
	ServerSender(SocketWrapper&);
	void send(sf::Packet);
private:
	SocketWrapper &socket_wrapper;
};

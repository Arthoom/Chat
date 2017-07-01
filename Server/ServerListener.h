#pragma once
#include "../SocketWrapper.h"

class Server;
#include "Server.h"

class ServerListener
{
public:
	ServerListener(SocketWrapper&, Server&);
	void operator()();
	bool isShutDown();
private:
	SocketWrapper &socket_wrapper;
	Server &server;
	bool shut_down = false;
};

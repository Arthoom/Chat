#pragma once
#include "../SocketWrapper.h"
#include "Server.h"

class Server;

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

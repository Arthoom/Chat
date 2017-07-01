#pragma once
#include "ServerSender.h"
class ServerListener;
#include "ServerListener.h"
#include "../SocketWrapper.h"
#include <thread>
#include <mutex>
#include <cassert>

class Server
{
public:
	Server(int port);
	void sendAll(sf::Packet);
	void serverLoop();

private:
	std::vector<ServerListener> listeners;
	std::vector<ServerSender> senders;
	std::vector< std::unique_ptr<SocketWrapper> > socket_wrappers;
	std::vector<std::thread> listen_threads;
	sf::TcpListener listen_socket;
	std::mutex mutex;
};
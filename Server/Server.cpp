#include "Server.h"

Server::Server(int port)
{
	assert(listen_socket.listen(port) == sf::Socket::Done);
}

void Server::serverLoop()
{
	std::unique_ptr<SocketWrapper> s(new SocketWrapper());
	socket_wrappers.emplace_back(std::move(s));
	while(listen_socket.accept(socket_wrappers.back()->getSocket()) == sf::Socket::Done)
	{
		listeners.emplace_back(ServerListener(*socket_wrappers.back(), *this));
		senders.emplace_back(ServerSender(*socket_wrappers.back()));
		listen_threads.emplace_back(std::thread(listeners.back()));
		listen_threads.back().detach();
	}
}

void Server::sendAll(sf::Packet packet)
{
	mutex.lock();
	for(int i = 0; i < (int)senders.size(); i++)
		if(!listeners[i].isShutDown())
			senders[i].send(packet);
	mutex.unlock();
}
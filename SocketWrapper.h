#pragma once
#include <mutex>
#include <SFML/Network.hpp>
#include <cassert>

class SocketWrapper
{
public:
	sf::TcpSocket& getSocket();
	SocketWrapper();
	SocketWrapper(std::string ip, int port);
	void lock();
	void unlock();
private:
	sf::TcpSocket socket;
	std::mutex mutex;
};

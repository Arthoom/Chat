#pragma once
#include <mutex>
#include <SFML/Network.hpp>

class SocketWrapper
{
public:
	sf::TcpSocket& getSocket();
	SocketWrapper();
	void lock();
	void unlock();
private:
	sf::TcpSocket socket;
	std::mutex mutex;
};
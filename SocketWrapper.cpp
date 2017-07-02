#include "SocketWrapper.h"

SocketWrapper::SocketWrapper() : socket() {}

SocketWrapper::SocketWrapper(std::string ip, int port)
{
	assert(getSocket().connect(ip, port) == sf::Socket::Done);
}

sf::TcpSocket& SocketWrapper::getSocket()
{
	return socket;
}

void SocketWrapper::lock()
{
	mutex.lock();
}

void SocketWrapper::unlock()
{
	mutex.unlock();
}

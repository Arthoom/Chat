#include "SocketWrapper.h"

SocketWrapper::SocketWrapper() : socket() {}

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
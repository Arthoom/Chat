#include "Client.h"
#include <cassert>

Client::Client(std::string ip, int port, std::string nick)
	: socket_wrapper(),
	client_listener(socket_wrapper),
	client_sender(socket_wrapper, nick),
	listener_thread(client_listener),
	sender_thread(client_sender)
{
	assert(socket_wrapper.getSocket().connect(ip, port) == sf::Socket::Done);
}

void Client::join()
{
	listener_thread.join();
}

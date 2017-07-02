#include "Client.h"

Client::Client(std::string ip, int port, std::string nick)
	: socket_wrapper(ip, port),
	client_listener(socket_wrapper),
	client_sender(socket_wrapper, nick),
	listener_thread(client_listener),
	sender_thread(client_sender) {}

void Client::join()
{
	listener_thread.join();
}

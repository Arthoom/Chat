#pragma once
#include "ClientListener.h"
#include "ClientSender.h"
#include "../SocketWrapper.h"
#include <thread>

class Client
{
public:
	Client(std::string ip, int port, std::string nick);
	void join();

private:
	SocketWrapper socket_wrapper;
	ClientListener client_listener;
	ClientSender client_sender;
	std::thread listener_thread, sender_thread;
};

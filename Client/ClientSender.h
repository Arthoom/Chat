#pragma once
#include "../SocketWrapper.h"

class ClientSender
{
public:
	ClientSender(SocketWrapper&, std::string);
	void operator()();
private:
	SocketWrapper &socket_wrapper;
	std::string nick;
};

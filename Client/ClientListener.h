#pragma once
#include "../SocketWrapper.h"

class ClientListener
{
public:
	ClientListener(SocketWrapper&);
	void operator()();
private:
	SocketWrapper &socket_wrapper;
};

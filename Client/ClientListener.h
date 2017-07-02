#pragma once
#include "../SocketWrapper.h"
#include <iostream>

class ClientListener
{
public:
	ClientListener(SocketWrapper&);
	void operator()();
private:
	SocketWrapper &socket_wrapper;
};

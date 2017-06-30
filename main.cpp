#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

int main()
{
	std::cout << "listen? (y/n)\n";
	char c;
	std::cin >> c;
	std::cout << "\nip to connect: \n";
	std::string ip;
	std::cin >> ip;
	std::cout << "\nport:\n";
	int port;
	std::cin >> port;

	sf::TcpSocket socket;

	if(c == 'y')
	{
		sf::TcpListener listener;
		if (listener.listen(port) != sf::Socket::Done)
			return std::cout << "xd\n", 0;
		std::cout << "listener listening on port\n";
		if (listener.accept(socket) != sf::Socket::Done)
			return std::cout << "xd\n", 0;
		std::cout << "listener accepted socket\n";

		while(true)
		{
			sf::Packet packet;
			int32_t x;
			socket.receive(packet);
			std::cout << "socket received packet\n";
			packet >> x;
			std::cout << "received id " << x << "\n";
		}
	}
	else
	{
		sf::Socket::Status status = socket.connect(ip, port);
		if (status != sf::Socket::Done)
			return std::cout << "xd\n", 0;

		for(int i = 0; i != 100; ++i)
		{
			sf::Packet packet;
			int32_t x = i;
			packet << x;
			socket.send(packet);
			std::cout << "send id " << x << "\n";
		}
	}

	return 0;
}

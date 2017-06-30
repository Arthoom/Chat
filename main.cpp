#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

int main()
{
	std::cout << "listen? (y/n)\n";
	char c;
	std::cin >> c;
	std::cout << "\nport:\n";
	int port;
	std::cin >> port;

	if(c == 'y')
	{
		sf::TcpSocket socket;

		sf::TcpListener listener;
		if (listener.listen(port) != sf::Socket::Done)
			return std::cout << "xd\n", 0;
		std::cout << "listener listening on port\n";
		if (listener.accept(socket) != sf::Socket::Done)
			return std::cout << "xd\n", 0;
		std::cout << "listener accepted socket\n";

		sf::Packet packet;
		while(socket.receive(packet) == sf::Socket::Done)
		{
			std::cout << "socket received packet\n";
			int32_t x;
			packet >> x;
			std::cout << "received id " << x << "\n";
		}
	}
	else
	{
		std::cout << "\nip to connect: \n";
		std::string ip;
		std::cin >> ip;
		std::cout << "\nmax id:\n";
		int max;
		std::cin >> max;

		sf::TcpSocket socket;

		sf::Socket::Status status = socket.connect(ip, port);
		if (status != sf::Socket::Done)
			return std::cout << "xd\n", 0;

		for(int i = 0; i != max; ++i)
		{
			sf::Packet packet;
			int32_t x = i;
			packet << x;
			socket.send(packet);
			std::cout << "send id " << x << "\n";
		}

		socket.disconnect();
	}

	return 0;
}

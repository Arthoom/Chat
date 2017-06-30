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
		if (listener.listen(53000) != sf::Socket::Done)
			return std::cout << "xd\n", 0;
		if (listener.accept(socket) != sf::Socket::Done)
			return std::cout << "xd\n", 0;

		while(true)
		{
			sf::Packet packet;
			int32_t x;
			socket.receive(packet);
			packet >> x;
			std::cout << "received " << x << "\n";
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
			std::cout << "send " << x << "\n";
		}
	}

	return 0;
}

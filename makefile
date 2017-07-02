CXX=g++
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -pthread
LDFLAGS=-std=c++11 -Wall
CPPFLAGS=-std=c++11 -Wall
RM=rm -f

SRCS=main.cpp Client/Client.cpp Client/ClientListener.cpp Client/ClientSender.cpp Server/Server.cpp Server/ServerListener.cpp Server/ServerSender.cpp SocketWrapper.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)
	rm main
	rm .depend

include .depend

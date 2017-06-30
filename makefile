CXX=clang++
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
LDFLAGS=-std=c++11 -Wall
CPPFLAGS=
RM=rm -f

SRCS=main.cpp
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

include .depend

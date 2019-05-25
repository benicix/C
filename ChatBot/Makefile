BuscarDados.o: BuscarDados.cpp buscarDados.hpp
	g++ -c BuscarDados.cpp -I/usr/include/cppconn -L/usr/lib -lmysqlcppconn 

Chat.o: Chat.cpp
	g++ -c Chat.cpp 

chatBot: Chat.o BuscarDados.o 
	g++ -I/usr/include/cppconn -L/usr/lib -lmysqlcppconn Chat.o BuscarDados.o -o chatBot
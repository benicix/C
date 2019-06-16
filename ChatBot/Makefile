BuscarDados.o: BuscarDados.cpp
	g++ -c BuscarDados.cpp -I/usr/include/cppconn -I/home/benicio/c++/ChatBot/CamadaVO -L/usr/lib -lmysqlcppconn -o /home/benicio/c++/ChatBot/ArquivosObjet/BuscarDados.o

Chat.o: Chat.cpp
	g++ -c Chat.cpp -I/home/benicio/c++/ChatBot/CamadaVO -I/home/benicio/c++/ChatBot/CamadaDao -o /home/benicio/c++/ChatBot/ArquivosObjet/chat.o

chatBot: Chat.o BuscarDados.o 
	g++ -I/usr/include/cppconn -L/usr/lib -lmysqlcppconn /home/benicio/c++/ChatBot/ArquivosObjet/chat.o /home/benicio/c++/ChatBot/ArquivosObjet/BuscarDados.o -o /home/benicio/c++/ChatBot/executavel/chatBot
	
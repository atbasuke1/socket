#pragma comment(lib, "Ws2_32.lib")
#pragma once

class client
{
public:
	int client_recv(void);
	int	client_send(char buff[]);
	~client(void);
};

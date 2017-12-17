/*
 * -----------------------------------------------------------------------------
 	Team1: 	Sean Horgan - 		K00196030
		Daniel Gadd - 		K00202350
		Samuel McSweeny - 	K00200955

 	Name: 	Client.c

 	Description:
		Creates a connecting socket. Connects
		to server and calls str_cli to handle
		I/O to and drom the server.

	Compile: gcc -o cli Client.c HandleIO.c
 * -----------------------------------------------------------------------------
 */

#include "AddedStuff.h"

int main (int argc, char **argv) 
{
	int sockfd;
	struct sockaddr_in servaddr;
	
	/* -- Check if server IP and Port are entered as arguments -- */
	if (argc <= 2)
		perror("usage: tcpcli <IPaddress>");

	/* -- Create a connecting socket -- */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	
	/* -- Create the Client address structure -- */
	bzero (&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	/* -- Connect to the server -- */
	connect(sockfd, (SA *) & servaddr, sizeof(servaddr));
	
	/* -- Handle I/O by calling str_cli -- */
	handleIO(stdin, sockfd);

	exit(0);
}

/*
\	赵子豪@2019年10月9日
*/
/*	daytimetcpcli.c	*/

#include "unp.h"

int
main (int argc, char **argv)
{
	int		sockfd, n;
	char 	recvline [MAXLINE + 1];
	struct sockaddr_in servaddr;

	if (argc != 2)
		err_quit("Usage: a.out <IPaddress>");

	if ( (sockfd = socket(AF_INEF, SOCK_STREAM, 0)) < 0)
		err_sys("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INEF;
	servaddr.sin_port = thons(13);			/*	daytime server	*/
	if (inet_pton(AF_INEF, argv[1], &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error for %s", argv[1]);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		err_sys("connect error");

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;			/*	null terminate	*/
		if (fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");

	exit(0);
}

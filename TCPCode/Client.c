/*!
 ******************************************************************************
 * @file          Client.c	     
 * @author        Kurt Stewart 
 * @date          2020-01-15
 * @brief         Creates a TCP client that tries to connect to a server 
 *
 * - taken from https://aticleworld.com/socket-programming-in-c-using-tcpip/
 * 					
 *					 
 *       
 ******************************************************************************
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>


/*!
 * @fn short SocketCreate(void)
 * @brief Creates the socket
 * @param void
 * @retval hsocket which is the socket object
 */

    //Create a Socket for server communication
    short SocketCreate(void)
    {
        short hSocket;
        printf("Create the socket\n");
        hSocket = socket(AF_INET, SOCK_STREAM, 0);
        return hSocket;
    }

/*!
 * @fn SocketConnect(int hSocket)
 * @brief Tries to connect to server at 127.0.0.1
 * @param hsocket
 * @retval iRetval is the return value from the server
 */
    int SocketConnect(int hSocket)
    {
        int iRetval=-1;
        int ServerPort = 90190;
        struct sockaddr_in remote= {0};
        remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //Local Host
        remote.sin_family = AF_INET;
        remote.sin_port = htons(ServerPort);
        iRetval = connect(hSocket,(struct sockaddr *)&remote,sizeof(struct sockaddr_in));
        return iRetval;
    }

/*!
 * @fn int SocketSend(int hSocket,char* Rqst,short lenRqst)
 * @brief Send the data to the server and set the timeout of 20 seconds
 * @param hsocket socket object
 * @param Rqst the message from client to server
 * @param lenRqst length of message from client to server
 * @retval shortRetval is the return value from the server
 */
    int SocketSend(int hSocket,char* Rqst,short lenRqst)
    {
        int shortRetval = -1;
        struct timeval tv;
        tv.tv_sec = 20;  /* 20 Secs Timeout */
        tv.tv_usec = 0;
        if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&tv,sizeof(tv)) < 0)
        {
            printf("Time Out\n");
            return -1;
        }
        shortRetval = send(hSocket, Rqst, lenRqst, 0);
        return shortRetval;
    }

/*!
 * @fn int SocketReceive(int hSocket,char* Rsp,short RvcSize)
 * @brief receive the data from the server
 * @param hsocket socket object
 * @param Rsp server reply
 * @param lenRqst length of server_reply (max 200)
 * @retval shortRetval is the return value from the server
 */
    int SocketReceive(int hSocket,char* Rsp,short RvcSize)
    {
        int shortRetval = -1;
        struct timeval tv;
        tv.tv_sec = 20;  /* 20 Secs Timeout */
        tv.tv_usec = 0;
        if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO,(char *)&tv,sizeof(tv)) < 0)
        {
            printf("Time Out\n");
            return -1;
        }
        shortRetval = recv(hSocket, Rsp, RvcSize, 0);
        printf("Response %s\n",Rsp);
        return shortRetval;
    }

void SocketSendData(int hSocket,int* Rqst,short lenRqst)
{
	int shortRetval = -1;
        struct timeval tv;
        tv.tv_sec = 20;  /* 20 Secs Timeout */
        tv.tv_usec = 0;
        if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&tv,sizeof(tv)) < 0)
        {
            printf("Time Out\n");
            return -1;
        }
        shortRetval = send(hSocket, Rqst, lenRqst, 0);
        return shortRetval;
    //printf("%d\n", age1);
    //printf("%d\n", age2);
}



//*************************************************************************************************
/*!
 * @fn int main(int argc, char *argv[])
 * @brief Starts the client, allows user to send a message across the terminal and waits for a response from the server.
 * @retval 1 if error 0 otherwise
 */
    int main(int argc, char *argv[])
    {
        int hSocket, read_size, ind;
        struct sockaddr_in server;
        //char SendToServer[100] = {0};
	int array[]={1,2,3,4};
	char* SendToServer = "This is a string";        
	char server_reply[200] = {0};
        //Create socket
        hSocket = SocketCreate();
        if(hSocket == -1)
        {
            printf("Could not create socket\n");
            return 1;
        }
        printf("Socket is created\n");
        //Connect to remote server
        if (SocketConnect(hSocket) < 0)
        {
            perror("connect failed.\n");
            return 1;
        }
        printf("Sucessfully conected with server\n");
        printf("Enter the Message: ");
	
printf("%s", SendToServer);
for (ind=0;ind<10;ind++){
	SocketSendData(hSocket, SendToServer, strlen(SendToServer));
	}

//SendToServer="T";
        //gets(SendToServer);
        //Send data to the server
        //SocketSend(hSocket, SendToServer, strlen(SendToServer));
        //Received the data from the server
        //read_size = SocketReceive(hSocket, server_reply, 200);
        printf("Server Response : %s\n\n",server_reply);
        close(hSocket);
        shutdown(hSocket,0);
        shutdown(hSocket,1);
        shutdown(hSocket,2);
        return 0;
    }

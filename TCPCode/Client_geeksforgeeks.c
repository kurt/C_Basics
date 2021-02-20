
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 5000


typedef struct
{
	float Fx;
	float Fy;
	float Fz;
	float Tx;
	float Ty;
	float Tz;
} FTSensorDataType;

typedef struct
{
	FTSensorDataType FT;
	int16_t Range[4];
} FootplateRecDataType;
 

// MAIN ------------------------------------------------------------------  
int main(int argc, char const *argv[]) 
{ 
	
FILE *fileAddress;
  // fileAddress = fopen("client2.txt", "w");
int i;

    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 
    //FootplateRecDataType buffer;
    char buffer[1024];// = {0}; 
    //char buffer;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "192.168.0.100", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
for(i=0;i<10;i++){
    	send(sock , hello , strlen(hello) , 0 ); 
    	printf("Hello message sent\n\r"); 
	//printf("the string is 1units long\n\r");
    

	valread = recv( sock , buffer, 1024,0);

	//printf("%lu\n\r", sizeof(buffer));
	printf("%s\n\r",buffer);
/*
    	int len = strlen(buffer);
    	printf("%d",len);
   	if (fileAddress != NULL) {
	fwrite(buffer, sizeof(buffer), 1, fileAddress);
/*
	for (i = 0; i < 1024; i++) {
           printf("Character we are writing to the File = %c \n", buffer[i]);
	   // Let us use our fputc
	   fputc (buffer[i], fileAddress);
	}
	printf("\n We have written the data successfully");
*/
	//fclose(fileAddress);		
   /*}
   else {
  	  printf("\n Unable to Create or Open the Sample.txt File");
   }
    //printf("%s\n",buffer );*/
} 
    return 0; 
} 


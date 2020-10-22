
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <stdlib.h>
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

// ------ Main -------------------------------------
int main(int argc, char const *argv[]) 
{ 
int i, int_command;    
int sock = 0, valread; 
FootplateRecDataType data_input;
float data_read=0;
    struct sockaddr_in serv_addr; 
  char *command = "91900";
	int_command= atoi(command);
	printf("command int: %d\n\r", int_command);
 	char *hello = "Good Day";
	int leng=strlen(hello);
	printf("good day length: %d", leng);
 	//int hello=1092;
	//char buffer;   
	char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
   //if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
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
// Wait for proper pairing
while(1){
   send(sock , hello , strlen(hello) , 0 );
   valread = recv( sock , buffer, sizeof(buffer),0);
//   for (ind=0;ind<4;ind++){   
	if(strcmp(buffer, "k23r")){
	break; 
	} 
//}
printf("%s\n",buffer); 
}

//Send command

while(1){//(i=0;i<10;i++){   
    send(sock , command , strlen(command) , 0 );
    valread = recv( sock , (void*)&data_input, sizeof(FootplateRecDataType),0); 
    data_read=data_input.FT.Fx;
    printf("%f\n",data_read); 
    if (data_read==33){
	break;
}
} // this works!!!
rc = close(sock);
printf("Socket Closed");
//Write a file 
FILE *outfile; 
      
    // open file for writing 
    outfile = fopen ("Random_Struct.dat", "w"); 
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        return 0; 
    } 
  
      
    // write struct to file 
    fwrite (&data_input, sizeof(FootplateRecDataType), 1, outfile);   
    if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n"); 
  
    // close file 
    fclose (outfile); 


    return 0; 
} 


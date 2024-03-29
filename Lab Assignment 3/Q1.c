/**
 	@file both.c

	@brief Write a socket program in C to determine class, Network and Host ID of an IPv4 address 

	@author Aman Jaiswal

	@date 01/08/2019
*/
 
#include<stdio.h> 
#include<string.h> 
/**
*	Function to find out the Class 
*	@author Aman Jaiswal
*	@param str:- ip address as string
*	@date 22/08/2019
*/
char findClass(char str[]) 
{ 
	//// storing first octet in arr[] variable 
	char arr[4]; 
	int i = 0; 
	while (str[i] != '.') 
	{ 
		arr[i] = str[i]; 
		i++; 
	} 
	i--; 

	//// converting str[] variable into number for 
	//// comparison 
	int ip = 0, j = 1; 
	while (i >= 0) 
	{ 
		ip = ip + (str[i] - '0') * j; 
		j = j * 10; 
		i--; 
	} 

	//// Class A 
	if (ip >=1 && ip <= 126) 
		return 'A'; 

	//// Class B 
	else if (ip >= 128 && ip <= 191) 
		return 'B'; 

	//// Class C 
	else if (ip >= 192 && ip <= 223) 
		return 'C'; 

	//// Class D 
	else if (ip >= 224 && ip <= 239) 
		return 'D'; 

	//// Class E 
	else
		return 'E'; 
} 
/**
*	Function to separate Network ID as well as Host ID and print them  
*	@author Aman Jaiswal
*	@param str:- ip address as string,and class of ip adress
*	@date 22/08/2019
*/

void separate(char str[], char ipClass) 
{ 
	//// Initializing network and host array to NULL 
	char network[12], host[12]; 
	for (int k = 0; k < 12; k++) 
		network[k] = host[k] = '\0'; 

	//// for class A, only first octet is Network ID 
	//// and rest are Host ID 
	if (ipClass == 'A') 
	{ 
		int i = 0, j = 0; 
		while (str[j] != '.') 
			network[i++] = str[j++]; 
		i = 0; 
		j++; 
		while (str[j] != '\0') 
			host[i++] = str[j++]; 
		printf("Network ID : %s\n", network); 
		printf("Host ID : %s\n", host); 
	} 

	//// for class B, first two octet are Network ID 
	//// and rest are Host ID 
	else if (ipClass == 'B') 
	{ 
		int i = 0, j = 0, dotCount = 0; 

		//// storing in network[] up to 2nd dot 
		//// dotCount keeps track of number of 
		//// dots or octets passed 
		while (dotCount < 2) 
		{ 
			network[i++] = str[j++]; 
			if (str[j] == '.') 
				dotCount++; 
		} 
		i = 0; 
		j++; 

		while (str[j] != '\0') 
			host[i++] = str[j++]; 

		printf("Network ID : %s\n", network); 
		printf("Host ID : %s\n", host); 
	} 

	//// for class C, first three octet are Network ID 
	//// and rest are Host ID 
	else if (ipClass == 'C') 
	{ 
		int i = 0, j = 0, dotCount = 0; 

		//// storing in network[] up to 3rd dot 
		//// dotCount keeps track of number of 
		//// dots or octets passed 
		while (dotCount < 3) 
		{ 
			network[i++] = str[j++]; 
			if (str[j] == '.') 
				dotCount++; 
		} 

		i = 0; 
		j++; 

		while (str[j] != '\0') 
			host[i++] = str[j++]; 

		printf("Network ID : %s\n", network); 
		printf("Host ID :%s\n", host); 
	} 

	//// Class D and E are not divided in Network 
	//// and Host ID 
	else
		printf("In this Class, IP address is not"
		" divided into Network and Host ID, so it belongs to Class D or E\n"); 
} 


int main() 
{ 
	char str[15] ; 
    printf("Enter a valid ip \n");
    scanf("%s", str);  	
    char ipClass = findClass(str); 
	printf("Given IP address belongs to Class : %c\n",ipClass); 
	separate(str, ipClass); 
	return 0; 
} 

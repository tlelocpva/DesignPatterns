#include <stdio.h>
#include <stdlib.h>		
#include <string.h>

#define LEN 10

struct pessoa
{
	char name[LEN +1];
	char lastName[LEN +1];
};


void printName( char * pName )
{
	printf("\n NAME = [%s]\n", pName);
}

void printLastName( char * pLastName )
{
	printf("\n LAST NAME = [%s]\n", pLastName);
}


int main()
{
	struct pessoa p;

	memset((void *)&p, 0, sizeof(p));

	memcpy( p.name, "Tobias1234", 10 );
	memcpy( p.lastName, "Oliveira", 8 );
	//memcpy( p.lastName, "Oliveira", 9 );

	printName( p.name );

	printLastName( p.lastName );
}


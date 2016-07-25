#include <stdio.h>
#include <stdlib.h>		
#include <string.h>
#include <cstdlib>
#include <iostream>
using namespace std;

void func( char **ptr )
{
	*ptr = (char *)malloc(10);

	memcpy( (char *) *ptr, "Tobias1234", 10 );


	return;

}

int main( )
{

	char *ptr = NULL;
	
	func(&ptr);

	cout<< "\n\n====================================================\n" << endl;
	cout<< "Valor de ptr: " << ptr << "\n" << endl;
	cout<< "====================================================\n" << endl;


}

#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int main( )
{

	int num_a = 10;
	int num_b = 5;

	int *p_num_a = NULL;
	int* p_num_b;

	cout<< "\n\n====================================================\n" << endl;
	cout<< "Endereço referenciado por p_num_a: " << p_num_a << "\n" << endl;
	cout<< "====================================================\n" << endl;

	cout<< "\n\n====================================================\n" << endl;
	cout<< "Endereço referenciado por p_num_b: " << p_num_b << "\n" << endl;
	cout<< "====================================================\n" << endl;

	p_num_a= &num_a;
	p_num_b= &num_b;

	cout<< "\n\n====================================================\n" << endl;
	cout<< "Endereço referenciado por p_num_a: " << p_num_a << "\n" << endl;
	cout<< "Valor contido no endereço de p_num_a: " << *p_num_a << "\n" << endl;
	cout<< "====================================================\n" << endl;
	cout<< "Endereço referenciado por  p_num_b: " << p_num_b << "\n" << endl;
	cout<< "Valor contido no endereço de p_num_b: " << *p_num_b << "\n" << endl;  
	cout<< "====================================================\n\n" << endl;


}
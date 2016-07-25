#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef int (*functionPtr)(int, int);

int soma( int val1, int val2 )
{
	std::cout << "RESULTADO = " << val1 + val2 << std::endl;
}

int subtracao( int val1, int val2 )
{
	std::cout << "RESULTADO = " << val1 - val2 << std::endl;
}

int multiplicacao( int val1, int val2)
{
	std::cout << "RESULTADO = " << val1 * val2 << std::endl;
}

int divisao( int val1, int val2 )
{
	std::cout << "RESULTADO = " << val1 / val2 << std::endl;
}





int main()
{
	int opcao;
	int val1;
	int val2;

	functionPtr functionArray[] =
	{
		soma,
		subtracao,
		multiplicacao,
		divisao
	};

	while(opcao != 4)
	{


		std::cout << "\n\nDigite o valor 1:" << std::endl;
		std::cin >> val1;

		std::cout << "Digite o valor 2:" << std::endl;
		std::cin >> val2;

		std::cout << "Entre com a opcao a ser executada" << std::endl;
		std::cout << "soma: 0 || subtracao: 1 || multiplicacao: 2 || divisao: 3 || sair: 4" << std::endl;
		std::cin >> opcao;

		while(opcao < 0 || opcao > 4)

		{

			std::cout << "Opção inválida!" << std::endl;
			std::cout << "soma: 0 || subtracao: 1 || multiplicacao: 2 || divisao: 3 || sair: 4" << std::endl;
			std::cin >> opcao;
		
		}



		(functionArray[opcao])(val1, val2);
	}

	return 0;
}
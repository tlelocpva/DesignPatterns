#include <memory>
#include <thread>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

struct Foo { // object to manage
	Foo() { std::cout << "Foo ctor"; }
	~Foo() { std::cout << "~Foo dtor"; }
};

typedef std::shared_ptr<Foo> sptr_foo;
typedef std::unique_ptr<Foo> uptr_foo;

void threadFunction(sptr_foo up1)
{
	getchar();
	std::cout << "shared pointer are here";
	getchar();
	std::cout << "deleting shared pointer";
	getchar();
}

void smartPointerExample( )
{
	uptr_foo up1(new Foo);
	uptr_foo aux;
	getchar();
	{
		uptr_foo up2(new Foo); //up2 now owns a Foos
		//aux = std::move(up2);
		getchar();
		std::cout << "up2 will be deleted";
		getchar();
	} // Foo deleted
	//std::cout << "up2 now belongs to aux";
	getchar();
}

sptr_foo sharedPointerExample( )
{
	std::thread t1;
	{
		sptr_foo up1(new Foo);
		sptr_foo aux;
		getchar();
		{
			sptr_foo up2(new Foo);
			getchar();
			aux = up2;
			std::cout << "up2 will be deleted";
			getchar();
		}
		std::cout << "EROOU, shared pointers tricks!";
		getchar();

		t1 = std::thread(threadFunction, aux);
		std::cout << "leaving the scope";
		getchar();
	}
	t1.join();
}

int main()
{
	int i = 0;

	while( i != 3 )
	{
		std::cout << "\n1 - Smart Pointer Example" << std::endl;
		std::cout << "2 - Shared Pointer Example" << std::endl;
		std::cout << "3 - Exit" << std::endl;
		std::cin >> i;

		switch(i)
		{
		case 1:
			std::cout << "Smart Pointer Example: ";
			getchar();
			getchar();
			smartPointerExample();
			break;
		case 2:
			std::cout << "Shared Pointer Example: ";
			getchar();
			getchar();
			sharedPointerExample();
			break;
		default:
			break;
		}

	}

	return 0;
}
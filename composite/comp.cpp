#include <iostream>
#include <vector>
#include <string>

using namespace std;


class option
{
public:
	virtual void show( string tab ) = 0;
};
typedef vector < option *> OptionVector;


class folder : public option
{
private:
	string name;
	OptionVector itens;
public:
	folder( string name)
	{
		this->name = name;
	}
	void addItem( option *op )
	{
		itens.push_back( op );
	}
	void show( string tab )
	{
		cout<< tab <<"d "<<name<<"\n";
		tab += "   ";
		for (int i = 0; i < itens.size(); i++)
		{			
			itens[i]->show( tab );
		}
	}
};


class file : public option
{
private:
	string name;
public:
	file( string name )
	{
		this->name = name;
	}
	void show( string tab )
	{
		cout << tab <<"-"<<name<<"\n";
	}
};


int main()
{
	file age("AgeIII.exe");
	file lembretes("lembretes.txt");
	file pdf("t1Arq2.pdf");
	folder trabalhos("trabalhos");
	file T3("T3.vhd");
	folder fotos("fotos");
	file eNois ("galera.png");

	folder desktop("desktop");

	desktop.addItem( &age );
	desktop.addItem( &trabalhos );
	desktop.addItem( &lembretes );
	trabalhos.addItem(&T3);
	trabalhos.addItem( &pdf );
	trabalhos.addItem( &fotos);
	fotos.addItem(&eNois);

	desktop.show("");

}
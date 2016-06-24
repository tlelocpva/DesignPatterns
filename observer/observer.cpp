#include <iostream>
#include <vector>
#include <string.h>


class Observer
{
	public:
		virtual void Update( ) = 0;
};


class Dog //Subject
{
	private:
		std::vector <Observer*> listeners;

	public:
		void attach( Observer *o )
		{
			listeners.push_back( o );
		}

		void bark( )
		{
			std::cout << "Dog: Woof Woof!!\n";

			int i;

			for (i=0; i < listeners.size(); i++)
				listeners[i]->Update( );
		}

};


class Cat: public Observer
{
	private:
		std::string m_name;

	public:
		Cat( Dog* dog, std::string name )
		{
			dog->attach( this );
			m_name = name;
		}


		void RunAway( ) 
		{
			std::cout <<  "CAT " << m_name << " run away!\n";
		}

		void Update( )
		{
			this->RunAway( );
		}

};



class Human: public Observer
{
	private:
		std::string m_name;

	public:
		Human( Dog* dog, std::string name)
		{
			dog->attach( this );
			m_name = name;
		}
		
		void WakeUp( )
		{
			std::cout << "HUMAN " << m_name << " woke up!\n";
		}
		
		void Update( )
		{
			this->WakeUp( );
		}

};



int main (void)
{

	Dog dog;

	Cat cat1( &dog, "Tom");
	Human human1( &dog, "Garry");
	//Human human2( &dog, "Larry");


	dog.bark();


}
#include <iostream>

class Singleton
{
	private:
		int m_value;

	public:
		int getValue()
		{
			return m_value;
		}

		void setValue( int value )
		{
			m_value = value;
		}

		static Singleton* getInstance()
		{
			static Singleton *instance = new Singleton();
			return instance;
		}
};


int main()
{
	printf("\n\nStarting singleton example...\n\n");


	//Create Sing1 and Sing2
	Singleton *sing1 = Singleton::getInstance();
	Singleton *sing2 = Singleton::getInstance();

	//Set value with Sing1
	printf("### SING1 SET value ###\n");
	sing1->setValue(45);

	//Read value with Sing1
	int sing1Value = sing1->getValue();
	printf("SING1 value = %d\n", sing1Value);

	

	//Read value with Sing2
	int sing2Value = sing2->getValue();
	printf("SING2 value = %d\n", sing2Value);

	//Set value with Sing2
	printf("### SING2 SET value ###\n");
	sing2->setValue(87);


	//Read value with Sing1
	sing1Value = sing1->getValue();
	printf("SING1 value = %d\n", sing1Value);

	//Read value with Sing2
	sing2Value = sing2->getValue();
	printf("SING2 value = %d\n", sing2Value);


	return 0;
}
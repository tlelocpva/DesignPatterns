#include <iostream>


// ####################################
// ############# STRATEGY #############
// ####################################


// class StrategyRun
// {
//     public:
//         virtual void run( ) = 0;
// };

        
// class SlowRun : public StrategyRun
// {
//     public:
//         void run( )
//         {
//             std::cout << "I'm running at a SLOW speed" << std::endl;
//         }
// };

// class FastRun : public StrategyRun
// {
//     public:
        
//         void run( )
//         {
//             std::cout << "I'm running at a FAST speed" << std::endl;
//         }
// };




// ####################################
// ############# NORMAL #############
// ####################################

class Feline
{
    
    public:
    
        virtual void display( ) = 0;
        virtual void roar( ) = 0;
        
        
        // virtual void setStrategyRun( StrategyRun *rcvRun )
        // {
        //     m_run = rcvRun;
        // }
        // virtual void executeRun( )
        // {
        //     std::cout << m_name << " runs : ";
        //     m_run->run( );
        // }
    
    protected:
    
        std::string m_name;
        
        //StrategyRun *m_run;
};


class Cat : public Feline
{
    
    public:
    
        Cat( std::string name )
        {
            m_name = name;
            //m_run = NULL;
        }
        
        void display( )
        {
            std::cout << m_name << " says: 'Hello, I'm a fat cat!' " <<  std::endl;
        }
        
        void roar( )
        {
            std::cout << m_name << " roar: 'I hate mondays!' " << std::endl;
        }
};    

class Tiger : public Feline
{
    public:
    
        Tiger( std::string name )
        {
            m_name = name;
            //m_run = new FastRun( );
        }
        void display( )
        {
            std::cout << m_name << " says: 'Hello, I'm a dangerous tiger!' " <<  std::endl;
        }
        
        void roar( )
        {
            std::cout << m_name << " roar: <<Tiger roar>>" << std::endl;
        }
};

class Lyon : public Feline
{
    public:

        Lyon( std::string name )
        {
            m_name = name;
            //m_run = new SlowRun( );
        }
        void display( )
        {
            std::cout << m_name << " says: 'Hello, I'm a brave lyon!' " <<  std::endl;
        }
        
        void roar( )
        {
            std::cout  << m_name << " roar: 'ZzZzZzZzZzZzZzZzZ' " << std::endl;
        }
};





int main (void)
{
    
    Feline* cat = new Cat( "Garfield" );
    Feline* tiger = new Tiger( "Tigrão" );
    Feline* lyon = new Lyon( "Simba" );
    
    std::cout << "\n";


    cat->display( );
    cat->roar( );

    
    std::cout << "\n\n";


    tiger->display( );
    tiger->roar( );
   // tiger->executeRun( );


    std::cout << "\n\n";

    
    lyon->display( );
    lyon->roar( );
    //lyon->executeRun( );


    /*
    std::cout << "\n\n";

    //Lyon is hungry, fast running is a must
    lyon->setStrategyRun( new FastRun );
    
    //Tiger was succesfull in his last hunt, he is heavy and can't  run like before
    tiger->setStrategyRun( new SlowRun );

    
    lyon->executeRun( );

    std::cout << "\n\n";

    
    tiger->executeRun( );
    */

    std::cout << "\n";

    return 0;
    
}
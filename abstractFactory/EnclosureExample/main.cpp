//
//  main.cpp
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#include <iostream>
#include "EnclosureHandle.h"
#include "ObanLinux.h"
#include "ObanWindows.h"


int getOption( )
{

	std::cout << "\n########################\n";
	std::cout << "#### Platform input ####\n";
	std::cout << "####                ####\n";
	std::cout << "#### 0 = exit       ####\n";
	std::cout << "#### 1 = linux      ####\n";
	std::cout << "#### 2 = windows    ####\n";
	std::cout << "########################\n";

	int option;
	std::cin >> option;
	option = option > 2 ? 0 : option;

	return option;
}


int main(int argc, const char * argv[]) {
    EnclosureHandle *handler;
    int option;

    std::cout << "\n\nSTART code\n\n";
    while( ( option = getOption( ) ) )
    {
		if( option == 0x01)
			handler = new EnclosureHandle( new ObanLinux( ) );		
		else
			handler = new EnclosureHandle( new ObanWindows( ) );
	    
	    handler->printEnclosure();
	}
 
    std::cout << "\n\nEND code\n\n";

    return 0;
}
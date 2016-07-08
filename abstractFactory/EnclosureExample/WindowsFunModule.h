//
//  WindowsFunModule.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef WindowsFunModule_h
#define WindowsFunModule_h

#include "FunModule.h"

class WindowsFunModule: public FunModule
{
private:
    std::string name;
public:
    WindowsFunModule( );
    std::string toString( );
};


WindowsFunModule::WindowsFunModule( )
{
    name = "Oban WINDOWS FUN Module";
}

std::string WindowsFunModule::toString( )
{
    return name;
}

#endif /* WindowsFunModule_h */

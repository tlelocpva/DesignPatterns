//
//  ObanFunModule.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef LinuxFunModule_h
#define LinuxFunModule_h

#include "FunModule.h"

class LinuxFunModule: public FunModule
{
private:
    std::string name;
public:
    LinuxFunModule( );
    std::string toString( );
};


LinuxFunModule::LinuxFunModule( )
{
    name = "Oban Linux FUN Module";
}

std::string LinuxFunModule::toString( )
{
    return name;
}

#endif /* ObanFunModule_h */

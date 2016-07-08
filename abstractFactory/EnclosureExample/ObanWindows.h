//
//  ObanWindows.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef ObanWindows_h
#define ObanWindows_h

#include <iostream>
#include <string>

#include "EnclosureAbstractFactory.h"
#include "WindowsSerial.h"
#include "WindowsFunModule.h"

class ObanWindows: public EnclosureAbstractFactory
{
public:
    Serial*         createSerial( );
    FunModule*      createFunModule( );
    //Disk* 		createDiskModule( );
};


Serial* ObanWindows::createSerial(  )
{
    return new WindowsSerial( );
}

FunModule* ObanWindows::createFunModule( )
{
    return new WindowsFunModule();
}


#endif /* ObanWindows_h */

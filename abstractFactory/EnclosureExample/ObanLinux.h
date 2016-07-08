//
//  ObanEnclosure.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef ObanEnclosure_h
#define ObanEnclosure_h

#include <iostream>
#include <string>

#include "EnclosureAbstractFactory.h"
#include "LinuxSerial.h"
#include "LinuxFunModule.h"

class ObanLinux: public EnclosureAbstractFactory
{
public:
    Serial*         createSerial( );
    FunModule*      createFunModule( );
    //Disk* 		createDiskModule( );
};


Serial* ObanLinux::createSerial(  )
{
    return new LinuxSerial( );
}

FunModule* ObanLinux::createFunModule( )
{
    return new LinuxFunModule();
}

/*Disk* ObanLinux::createDiskModule( )
{
    return new LinuxDiskModule();
}*/

#endif /* ObanEnclosure_h */

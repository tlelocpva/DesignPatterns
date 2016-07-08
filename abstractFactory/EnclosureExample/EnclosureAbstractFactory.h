//
//  EnclosureAbstractFactory.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef EnclosureAbstractFactory_h
#define EnclosureAbstractFactory_h
#include <iostream>
#include <string>

#include "Serial.h"
#include "FunModule.h"

class EnclosureAbstractFactory
{
public:
    virtual Serial*		createSerial( ) = 0;
    virtual FunModule* 	createFunModule( ) = 0;

//    virtual Disk* 		createDiskModule( ) = 0;
};


#endif /* EnclosureAbstractFactory_h */

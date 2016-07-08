//
//  EnclosureHandle.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef EnclosureHandle_h
#define EnclosureHandle_h
#include <iostream>
#include "EnclosureAbstractFactory.h"

class EnclosureHandle
{
private:
    EnclosureAbstractFactory    *encFactory;
    Serial                      *serial;
    FunModule                   *funModule;
    
public:
    EnclosureHandle( EnclosureAbstractFactory *);
    void printEnclosure( );
};

EnclosureHandle::EnclosureHandle( EnclosureAbstractFactory *enclosureAbstractFactory )
{
    encFactory = enclosureAbstractFactory;
    
    serial = encFactory->createSerial();
    funModule = encFactory->createFunModule();
}

void EnclosureHandle::printEnclosure()
{
    std::cout << serial->toString() << "  +  " << funModule->toString() + "\n";
}


#endif /* EnclosureHandle_h */

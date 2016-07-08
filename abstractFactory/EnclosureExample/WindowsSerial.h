//
//  ObanWindowsSerial.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef WindowsSerial_h
#define WindowsSerial_h

#include "Serial.h"

class WindowsSerial: public Serial
{
private:
    
public:
    WindowsSerial( );
    std::string getPort( );
    std::string getPlatform( );
    std::string toString( );
};


WindowsSerial::WindowsSerial( )
{
    port = "COM1";
    platform = "Oban WINDOWS";
}

std::string WindowsSerial::getPort( )
{
    return port;
}

std::string WindowsSerial::getPlatform( )
{
    return platform;
}

std::string WindowsSerial::toString( )
{
    return platform + " SERIAL PORT = " + port;
}

#endif /* WindowsSerial_h */

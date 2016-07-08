//
//  ObanSerial.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef LinuxSerial_h
#define LinuxSerial_h

#include "Serial.h"

class LinuxSerial: public Serial
{
private:
    
public:
    LinuxSerial( );
    std::string getPort( );
    std::string getPlatform( );
    std::string toString( );
};


LinuxSerial::LinuxSerial( )
{
    port = "PTY0";
    platform = "Oban LINUX";
}

std::string LinuxSerial::getPort( )
{
    return port;
}

std::string LinuxSerial::getPlatform( )
{
    return platform;
}

std::string LinuxSerial::toString( )
{
    return platform + " SERIAL PORT = " + port;
}
#endif /* ObanSerial_h */

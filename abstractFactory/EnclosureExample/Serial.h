//
//  Serial.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef Serial_h
#define Serial_h

#include <string>

class Serial
{
private:

public:
    std::string port;
    std::string platform;

    virtual std::string getPort( ) = 0;
    virtual std::string getPlatform( ) = 0;
    virtual std::string toString( ) = 0;
};

#endif /* Serial_h */

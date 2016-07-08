//
//  FunModule.h
//  AbstractFactoryExample
//
//  Created by Anderson Armani on 07/07/16.
//  Copyright © 2016 Anderson Armani. All rights reserved.
//

#ifndef FunModule_h
#define FunModule_h

#import <string>

class FunModule
{
private:
    std::string name;
public:
    virtual std::string toString( ) = 0;
};

#endif /* FunModule_h */

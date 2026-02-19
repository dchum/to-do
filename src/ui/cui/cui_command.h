#pragma once

namespace cui 
{

class Command{
public:
    virtual ~Command(){}

    virtual void Execute( void ) = 0;

protected:
    Command(){}
};

}//namespace cui
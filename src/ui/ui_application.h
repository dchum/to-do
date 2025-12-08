#pragma once


class Application
{

protected:
    Application (  ) {};

public:
    virtual ~Application()=default;

    virtual void exec( void ) = 0;
};

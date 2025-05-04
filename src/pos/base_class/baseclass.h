#pragma once

namespace pos
{

class BaseClass
{
private:
    int x; //NOTE - подумать, что выделить в общий интерфейс для всех базовых классов

public:
    BaseClass( void ) { x = 0; };
    virtual ~BaseClass() {};
};

}
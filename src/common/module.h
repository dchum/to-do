#pragma once


#include <deque>
#include <type_traits>
#include <utility>
#include <memory>
#include <vector>

#include "message.h"
#include "module_id.h"

namespace common
{    

class Module
{
    ModuleId module_id_;

    std::deque<Message>  inbox_;
    std::deque<Message> outbox_;

    std::vector<ModuleId> subscriptions_;

protected:
    Message take_input_msg_internal( void );

    void push_output_msg_internal( Message && msg );

    void subscribe( ModuleId module_id ) { subscriptions_.push_back( module_id ); }

public:
    void push_input_msg( Message && msg );
    void push_input_msg( const Message & msg ) { push_input_msg( Message( msg ) ); }

    Message take_output_msg ( void );

    virtual ~Module() = default;

    const std::vector<ModuleId> & get_subscriptions( void ) const { return subscriptions_; }

    ModuleId get_module_id( void ) const { return module_id_; }
};//class Module


inline Message Module::take_input_msg_internal(void)
{
    auto msg = std::move( inbox_.front() );
    inbox_.pop_front();
    return msg;
}

inline void Module::push_output_msg_internal( Message &&msg )
{
    outbox_.push_back( std::move( msg ) );
}

inline void Module::push_input_msg( Message &&msg )
{
    inbox_.push_back( std::move( msg ) );
}

inline Message Module::take_output_msg(void)
{
    auto msg = std::move( outbox_.front() );
    outbox_.pop_front();
    return msg;
}

};
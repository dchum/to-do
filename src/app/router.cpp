#include "router.h"

#include "common/message.h"

void app::Router::AddModule(common::Module &md)
{
    if ( std::find_if( modules_.begin(), modules_.end(), [&md]( auto && m ) 
                    { return md.get_module_id() == m.get().get_module_id(); } ) != modules_.end() )
    {
        return;
    }

    modules_.push_back( std::ref( md ) );

    auto && const subscriptions = md.get_subscriptions();
    for ( auto && sub : subscriptions )
    {
        subscriptions_[sub].push_back( std::ref( md ) );
    }
}

void app::Router::update(void)
{
    for ( auto && md : modules_ )
    {
        Message msg = md.get().take_output_msg();

        ModuleId receiver = msg.header.receiver;
        if ( receiver != ModuleId::Invalid )// если есть получатель, то ищем его в списке модулей и передаем сообщение
        {
            auto && it = std::find_if( modules_.begin(), modules_.end(), [&receiver]( auto && m ) 
                        { return receiver == m.get().get_module_id(); } );

            if ( it != modules_.end() )
            {
                it->get().push_input_msg( std::move( msg ) );
            }
        }
        else // если получателя нет, то ищем подписчиков на этот тип сообщения и передаем им сообщение
        {
            auto && it = subscriptions_.find( msg.header.sender );
            if ( it != subscriptions_.end() )
            {
                for ( auto && sub : it->second )
                {
                    sub.get().push_input_msg( std::move( msg ) );
                }
            }
        }
    }
}

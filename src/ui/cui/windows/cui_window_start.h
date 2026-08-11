#pragma once

#include "cui_window.h"

namespace cui
{
    class WindowStart final: public Window
    {
    public:
        WindowStart( CUIScreen& screen );

        void init() override;

		virtual std::optional<CommandMessage> update( int key ) override { return std::nullopt; };
		
	};
}

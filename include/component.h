#pragma once
#include <internal.h>


namespace VisualConstruct
{
    class Component
    {
    public:
        virtual void initialize() = 0;
        virtual void update() =0;

        std::string componentId; 
    };
}

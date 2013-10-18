#include <openlane/component_provider.h>
#include "component.h"

#include <stdio.h>

ComponentOne::ComponentOne(openlane::IComponentProvider* cp) : openlane::IComponent(cp)
{
    icp->RegisterComponent(ID, this);
}

ComponentOne::~ComponentOne()
{
    icp->UnregisterComponent(ID, this);
}

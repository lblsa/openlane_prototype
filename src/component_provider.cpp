#include <openlane/component_provider.h>
#include <openlane/module.h>
#include <iostream>

typedef uint32_t (*LoadComponentType)(void *ctx);
LoadComponentType LCT;

namespace openlane {

ComponentProvider::ComponentProvider() :
    xml_parser()
{
}

ComponentProvider::~ComponentProvider() {
}

ErrorCode ComponentProvider::LoadComponent(const char* filename) {
    if (!filename)
        return InvalidArgument;

    ErrorCode result = parser.Parse(filename);
    if (result != Ok)
        return result;

    DynamicLibrary module;
    ErrorCode res = module.Load("./libcomponent1.so");
    res = module.GetSymbol("LoadComponent", LCT);
    if (Ok == res)
        LCT(this);

    std::cout << "ComponentProvider::LoadComponent\tfilename=" << filename << std::endl;
    return Ok;
}

ErrorCode ComponentProvider::RegisterComponent(uint32_t id, IComponent* c) {
    std::cout << "ComponentProvider::RegisterComponent\tfilename=" << id << std::endl;
    return Ok;
}
ErrorCode ComponentProvider::UnregisterComponent(uint32_t id, IComponent* c) {
    std::cout << "ComponentProvider::UnregisterComponent\tid=" << id << std::endl;
    return Ok;
}
    
} /* openlane */

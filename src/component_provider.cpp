#include <openlane/component_provider.h>
#include <openlane/module.h>
#include <iostream>

typedef uint32_t (*ComponentFn)(void *ctx);
ComponentFn LCT;

namespace openlane {

ComponentProvider::ComponentProvider() :
    xml_parser()
{
}

ComponentProvider::~ComponentProvider() {
    ComponentReverseIterator b = modules.rbegin();
    ComponentReverseIterator e = modules.rend();

    for(;b != e; ++b) {
        ErrorCode res = (*b)->GetSymbol("UnloadComponent", LCT);
        if (Ok == res)
            LCT(this); // FIXME
    }

}

ErrorCode ComponentProvider::LoadComponent(const char* filename) {

    ErrorCode res = Ok;
    try
    {
        DynamicLibraryPtr module(new DynamicLibrary);
        res = module->Load(filename);

        if (Ok == res)
            res = module->GetSymbol("LoadComponent", LCT);

        if (Ok == res)
            if (LCT(this) == 0) res = Ok; // FIXME

        if (Ok == res)
            modules.push_back(module);
    }
    catch(const std::bad_alloc&)
    {
        res = NoMemory;
    }

    return res;
}
ErrorCode ComponentProvider::Initialize(const char* filename) {
    if (!filename)
        return InvalidArgument;

    ErrorCode result = xml_parser.Parse(filename);
    if (result != Ok)
        return result;

    std::cout << "ComponentProvider::LoadComponent\tfilename=" << filename << std::endl;
    return Ok;
}

ErrorCode ComponentProvider::RegisterComponent(uint32_t id, CreateComponentFn fun) {
    std::cout << "ComponentProvider::RegisterComponent\tid=" << id << std::endl;
    dic[id] = fun;
    return Ok;
}

ErrorCode ComponentProvider::UnregisterComponent(uint32_t id) {
    std::cout << "ComponentProvider::UnregisterComponent\tid=" << id << std::endl;
    return Ok;
}
    
} /* openlane */

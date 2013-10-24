#include <openlane/component_provider.h>
#include <openlane/module.h>
#include <iostream>
#include <string>

namespace {
typedef uint32_t (*ComponentFn)(void *ctx);
ComponentFn LCT;
}

namespace openlane {

std::string MakeModuleName(const char* name) {
    std::string module("lib");
    module.append(name);
    module.append(".so");
    return module;
}

std::string MakeConfigName(const char* name) {
    std::string config(name);
    config.append(".xml");
    return config;
}


ComponentProvider::ComponentProvider() :
    xml_parser(this)
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
        std::cout << "component_provider\tLoad component " << filename << ", result=" << res << std::endl;

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
    std::cout << "component_provider\tInitialize" << std::endl;
    configs.push_back(std::string(filename));

    while(!configs.empty()) {
        LoadConfig(configs.begin()->c_str());
        configs.erase(configs.begin());
    }
    return Ok;
}

ErrorCode ComponentProvider::LoadConfig(const char* filename) {
    if (!filename)
        return InvalidArgument;

    std::cout << "component_provider\tParse config, name=" << filename << std::endl;
    ErrorCode result = xml_parser.Parse(filename);
    if (result != Ok)
        return result;

    return Ok;
}

ErrorCode ComponentProvider::RegisterComponent(uint32_t id, CreateComponentFn fun) {
    std::cout << "component_provider\tRegisterComponent id=" << id << std::endl;
    dic[id] = fun;
    return Ok;
}

ErrorCode ComponentProvider::UnregisterComponent(uint32_t id) {
    std::cout << "component_provider\tUnregisterComponent id=" << id << std::endl;
    return Ok;
}

void ComponentProvider::OnLoadComponent(const char* name) {
    std::string module_name = MakeModuleName(name);
    LoadComponent(module_name.c_str());
}
    
void ComponentProvider::OnLoadConfig(const char* name) {
    std::string config_name = MakeConfigName(name);
    configs.push_back(config_name);
}
 
} /* openlane */

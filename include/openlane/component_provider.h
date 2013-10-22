#ifndef COMPONENT_PROVIDER_H
#define COMPONENT_PROVIDER_H

#include <openlane/openlane.h>
#include <openlane/module.h>
#include <openlane/component.h>
#include <openlane/module_xml_parser.h>

#include <string>
#include <vector>
#include <map>

#include <stdio.h>

namespace openlane {

class ComponentProvider {
  public:
    ComponentProvider();
    virtual ~ComponentProvider();

    ErrorCode Initialize(const char* filename);
    ErrorCode LoadComponent(const char* filename);
    virtual ErrorCode RegisterComponent(uint32_t id, CreateComponentFn fun);
    virtual ErrorCode UnregisterComponent(uint32_t id);

    template<class T>
    void* CreateObject(T& c) {
            std::map<uint32_t, CreateComponentFn>::const_iterator pos = dic.find(T::element_t::ID);
            if (pos == dic.end())
                return NULL;

            CreateComponentFn func = pos->second;

            void* obj;
            func(this, &obj);

            c.reset(static_cast<typename T::element_t*>(obj));
            return obj;
        }


  private:
    ComponentProvider(const ComponentProvider&);
    ComponentProvider operator=(const ComponentProvider&);

    ModuleXmlParser xml_parser;

    typedef std::vector<DynamicLibraryPtr>::reverse_iterator ComponentReverseIterator;
    std::vector<DynamicLibraryPtr> modules;
    std::map<uint32_t, CreateComponentFn> dic;
};
    
} /* openlane */

#endif /* end of include guard: COMPONENT_PROVIDER_H */

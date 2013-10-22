#ifndef COMPONENT_PROVIDER_H
#define COMPONENT_PROVIDER_H

#include <openlane/openlane.h>
#include <openlane/module.h>
#include <openlane/component.h>
#include <openlane/module_xml_parser.h>

#include <string>
#include <vector>

namespace openlane {

class IComponentProvider {
  public:
    virtual ~IComponentProvider() {};
    virtual ErrorCode RegisterComponent(uint32_t id, IComponent* c) = 0;
    virtual ErrorCode UnregisterComponent(uint32_t id, IComponent* c) = 0;
};

class ComponentProvider : public IComponentProvider {
  public:
    ComponentProvider();
    virtual ~ComponentProvider();

    ErrorCode LoadComponent(const char* filename);
    virtual ErrorCode RegisterComponent(uint32_t id, IComponent* c);
    virtual ErrorCode UnregisterComponent(uint32_t id, IComponent* c);

  private:
    ComponentProvider(const ComponentProvider&);
    ComponentProvider operator=(const ComponentProvider&);

    ModuleXmlParser xml_parser;

    typedef std::vector<DynamicLibraryPtr>::const_iterator ComponentConstIterator;
    std::vector<DynamicLibraryPtr> components;
};
    
} /* openlane */

#endif /* end of include guard: COMPONENT_PROVIDER_H */

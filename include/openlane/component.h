#ifndef COMPONENT_H
#define COMPONENT_H

namespace openlane {

class IComponent {
  public:
//    enum { ID = -1 }; // FIXME

    virtual ~IComponent() {};
};

typedef void* (*CreateComponentFn)(void* ctx, void** obj);

} /* openlane */


#endif /* end of include guard: COMPONENT_H */

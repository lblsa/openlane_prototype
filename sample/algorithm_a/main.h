#ifndef MAIN_H
#define MAIN_H

#include <openlane/visibility.h>

extern "C" {
uint32_t DLL_PUBLIC LoadComponent(void *ctx);
uint32_t DLL_PUBLIC UnloadComponent(void *ctx);
}

#endif /* end of include guard: MAIN_H */


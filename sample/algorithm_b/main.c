#include "main.h"
#include <stdio.h>

DLL_PUBLIC void LoadComponent(void *ctx) {
    printf("component1 loaded\n");
}

DLL_PUBLIC void UnloadComponent(void *ctx) {
    printf("component1 unloaded\n");
}

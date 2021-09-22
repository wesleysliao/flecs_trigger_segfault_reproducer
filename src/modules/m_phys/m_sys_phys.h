#ifndef _HOVERRUN_M_SYS_PHYS_H_
#define _HOVERRUN_M_SYS_PHYS_H_

#include <flecs.h>


typedef struct PhysBody {
    int body;
} PhysBody;


typedef struct Velocity {
    double x;
    double y;
    double angular;
} Velocity;

typedef struct PhysAttach {
    double x;
    double y;
} PhysAttach;


typedef struct MSysPhys {
    ECS_DECLARE_COMPONENT(PhysBody);
    ECS_DECLARE_COMPONENT(PhysAttach);
    ECS_DECLARE_COMPONENT(Velocity);
} MSysPhys;

void MSysPhysImport(ecs_world_t * world);

#define MSysPhysImportHandles(handles)  \
    ECS_IMPORT_COMPONENT(handles, PhysBody);           \
    ECS_IMPORT_COMPONENT(handles, PhysAttach);         \
    ECS_IMPORT_COMPONENT(handles, Velocity);           \

ECS_COMPONENT_DECLARE(PhysBody);
ECS_COMPONENT_DECLARE(PhysAttach);
ECS_COMPONENT_DECLARE(Velocity);

#endif // _HOVERRUN_M_SYS_PHYS_H_

#include "m_sys_phys.h"

#include <flecs.h>

void PhysShape_attach(ecs_iter_t * it) {
    PhysAttach * term_attach = ecs_term(it, PhysAttach, 1);
    PhysBody * term_body = ecs_term(it, PhysBody, 2);

    for(int i = 0; i < it->count; i++) {
    }
}


void Velocity_set(ecs_iter_t * it) {
    PhysBody * term_body = ecs_term(it, PhysBody, 1);
    Velocity * term_vel = ecs_term(it, Velocity, 2);

    for (int i = 0; i < it->count; i++) {
    }
}


void MSysPhysImport(ecs_world_t * world) {
    ECS_MODULE(world, MSysPhys);

    ECS_COMPONENT_DEFINE(world, PhysBody);
    ECS_COMPONENT_DEFINE(world, PhysAttach);
    ECS_COMPONENT_DEFINE(world, Velocity);

    ECS_EXPORT_COMPONENT(PhysBody);
    ECS_EXPORT_COMPONENT(PhysAttach);
    ECS_EXPORT_COMPONENT(Velocity);

    ECS_OBSERVER(world, PhysShape_attach, EcsOnSet,
               [in] PhysAttach(This, *),
               [in] PhysBody(super(PhysAttach)));

    ECS_OBSERVER(world, Velocity_set, EcsOnSet,
                 [in] PhysBody,
                 [in] Velocity);

}

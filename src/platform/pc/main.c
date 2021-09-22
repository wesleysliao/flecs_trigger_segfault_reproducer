#include <flecs.h>

#include "m_sys_phys.h"

int main(int argc, char * argv[]){

    ecs_world_t * world = ecs_init_w_args(argc, argv);
    ecs_set_target_fps(world, 20);

    ECS_IMPORT(world, MSysPhys);

    int loop = 0;
    while(ecs_progress(world, 0) && loop < 20) loop++;

    return ecs_fini(world);
}

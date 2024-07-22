#include "main.h"

void    game_loop(t_main *rt)
{
    init_mlx(&rt->mlx);
    draw_rectangle(rt);
    handle_events(rt);
    mlx_loop(rt->mlx.mlx_ptr);
}

int main(void)
{
    t_main  *rt;

    rt = init_main();
    if (!rt)
        exit(1);
    game_loop(rt);
    free(rt);
}

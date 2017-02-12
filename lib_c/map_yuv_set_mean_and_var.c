#include  "include/image.h"

void map_yuv_set_mean_and_var(struct map_yuv_t *map)
{
    int w,h;

    map->ym = 0.0;
    for(h=0; h<map->ht; h++){
        for(w=0; w<map->wt; w++){
            map->ym += map->y[h][w];
        }
    }

    map->ym /= (double)(map->ht * map->wt);

    map->yv = 0.0;
    for(h=0; h<map->ht; h++){
        for(w=0; w<map->wt; w++){
            map->yv += (map->y[h][w] - map->ym) * (map->y[h][w] - map->ym);
        }
    }

    map->yv /= (double)(map->ht * map->wt);
}

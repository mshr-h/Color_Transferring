#include "include/image.h"

struct img_rgb_t *map_to_img_rgb(struct map_rgb_t *map)
{
    int w, h;
    int r, g, b;

    struct img_rgb_t *out;

    out=img_rgb_create(map->wt,map->ht,0);

    for(h=0;h<map->ht;h++){
        for(w=0;w<map->wt;w++){
            r = (int)(255.0*map->r[h][w]);
            g = (int)(255.0*map->g[h][w]);
            b = (int)(255.0*map->b[h][w]);
            if (r > 255)    r = 255;
            else if (r < 0) r = 0;
            if (g > 255)    g = 255;
            else if (g < 0) g = 0;
            if (b > 255)    b = 255;
            else if (b < 0) b = 0;
            out->r[h][w]=(unsigned char)r;
            out->g[h][w]=(unsigned char)g;
            out->b[h][w]=(unsigned char)b;
        }
    }

    return out;
}

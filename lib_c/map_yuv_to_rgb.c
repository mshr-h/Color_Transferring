#include  "include/image.h"

//0=<y<=1.0, -0.436=<u<=0.436, -0.615=<v<=0.615 
struct map_rgb_t *map_yuv_to_rgb(struct map_yuv_t *in)
{
    int w,h;
    struct map_rgb_t *out = map_rgb_create(in->wt,in->ht,0.0);

    for(h=0;h<in->ht;h++){
        for(w=0;w<in->wt;w++){
            out->r[h][w]=1.000*in->y[h][w]                  +1.140*in->v[h][w];
            out->g[h][w]=1.000*in->y[h][w]-0.395*in->u[h][w]-0.581*in->v[h][w];
            out->b[h][w]=1.000*in->y[h][w]+2.032*in->u[h][w]                  ;
        }
    }

    return out;
}

#include  "include/image.h"

void luminance_remapping(struct map_yuv_t *src, struct map_yuv_t *target)
{
    int w,h;

    map_yuv_set_mean_and_var(src);
    map_yuv_set_mean_and_var(target);

    for(h=0; h<src->ht; h++){
        for(w=0; w<src->wt; w++){
            src->y[h][w] = (sqrt(target->yv) / sqrt(src->yv)) * (src->y[h][w] - src->ym) + target->ym;
        }
    }

    src->ym=target->ym;
    src->yv=target->yv;
}

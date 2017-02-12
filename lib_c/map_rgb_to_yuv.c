#include  "include/image.h"

struct map_yuv_t *map_rgb_to_yuv(struct map_rgb_t *in)
{
	int w,h;

	struct map_yuv_t *out;

	out=map_yuv_create(in->wt,in->ht,0.0);

	for(h=0;h<in->ht;h++){
		for(w=0;w<in->wt;w++){
			out->y[h][w]= 0.299*in->r[h][w]+0.587*in->g[h][w]+0.114*in->b[h][w];
            out->u[h][w]=-0.147*in->r[h][w]-0.289*in->g[h][w]+0.436*in->b[h][w];
			out->v[h][w]= 0.615*in->r[h][w]-0.515*in->g[h][w]-0.100*in->b[h][w];			

		}
	}

	return out;
}

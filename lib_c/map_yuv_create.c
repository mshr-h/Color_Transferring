#include  "include/image.h"

struct map_yuv_t *map_yuv_create(int wt, int ht, double init)
{
    struct map_yuv_t *img;

    img=(struct map_yuv_t *)malloc(sizeof(struct map_yuv_t));

    img->wt=wt;
    img->ht=ht;

    img->y=Malloc2D_dbl(img->wt,img->ht,init);
    if(img->y==NULL){
		printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
	  exit(-1);
	}
    img->u=Malloc2D_dbl(img->wt,img->ht,init);
    if(img->u==NULL){
		printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
	  exit(-1);
	}
    img->v=Malloc2D_dbl(img->wt,img->ht,init);
    if(img->v==NULL){
		printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
	  exit(-1);
	}

    return img;
}

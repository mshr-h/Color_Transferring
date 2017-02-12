#include "include/image.h"

struct arry_smpl_t *generate_regular_samples(struct img_rgb_t *src_rgb, struct img_rgb_t *trgt_rgb, int wnd_ht, int wnd_wt)
{
    struct map_rgb_t *map_rgb=img_to_map_rgb(src_rgb);
    struct map_yuv_t *src_yuv=map_rgb_to_yuv(map_rgb);
    map_rgb_destruct(map_rgb);

    map_rgb=img_to_map_rgb(trgt_rgb);
    struct map_yuv_t *trgt_yuv=map_rgb_to_yuv(map_rgb);
    map_rgb_destruct(map_rgb);

    luminance_remapping(src_yuv,trgt_yuv);

    int w,h,lw,lh;
    int hlf_wt,hlf_ht;
    double mean,var;

    hlf_wt=wnd_ht/2;
    hlf_ht=wnd_wt/2;

    unsigned long  num_of_smpls=0;
    for(h=hlf_ht;h<src_yuv->ht-hlf_ht;h+=SMPLS_INTERVAL){
        for(w=hlf_wt;w<src_yuv->wt-hlf_wt;w+=SMPLS_INTERVAL){
            num_of_smpls++;
        }
    }

    struct arry_smpl_t *smpls=arry_smpl_create(num_of_smpls);

    smpls->num_of_smpls=0;
    for(h=hlf_ht;h<src_yuv->ht-hlf_ht;h+=SMPLS_INTERVAL){
        for(w=hlf_wt;w<src_yuv->wt-hlf_wt;w+=SMPLS_INTERVAL){

            smpls->elm[smpls->num_of_smpls].w=w;
            smpls->elm[smpls->num_of_smpls].h=h;
            smpls->elm[smpls->num_of_smpls].y=src_yuv->y[h][w];
            smpls->elm[smpls->num_of_smpls].u=src_yuv->u[h][w];
            smpls->elm[smpls->num_of_smpls].v=src_yuv->v[h][w];

            //compute mean and var
            mean=0.0; var=0.0;
            for(lh=-hlf_ht;lh<=hlf_ht;lh++){
                for(lw=-hlf_wt;lw<=hlf_wt;lw++){
                    mean+=src_yuv->y[h+lh][w+lw];
                }
            }
            mean/=(double)(wnd_wt*wnd_ht);
            for(lh=-hlf_ht;lh<=hlf_ht;lh++){
                for(lw=-hlf_wt;lw<=hlf_wt;lw++){
                    var+=(src_yuv->y[h+lh][w+lw]-mean)*(src_yuv->y[h+lh][w+lw]-mean);
                }
            }
            var/=(double)(wnd_wt*wnd_ht);

            smpls->elm[smpls->num_of_smpls].ym=mean;
            smpls->elm[smpls->num_of_smpls].yv=var;

            smpls->num_of_smpls++;

        }
    }

    map_yuv_destruct(src_yuv);

    return smpls;
}

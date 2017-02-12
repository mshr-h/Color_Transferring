#include "include/image.h"

struct img_rgb_t *transfer_color(struct img_rgb_t *trgt, struct img_rgb_t *src, int wnd_ht, int wnd_wt)
{
    struct map_rgb_t *trgt_map_rgb = img_to_map_rgb(trgt);
    struct map_yuv_t *trgt_map_yuv = map_rgb_to_yuv(trgt_map_rgb);
    struct arry_smpl_t *smpls = generate_regular_samples(src, trgt, wnd_ht, wnd_wt);

    int h,w,lh,lw;
    int hlf_wt,hlf_ht;
    unsigned long indx;
    int num_of_pixs;
    double mean, var;

    hlf_wt=wnd_ht/2;
    hlf_ht=wnd_wt/2;

    for(h=0;h<trgt_map_yuv->ht;h++){
        for(w=0;w<trgt_map_yuv->wt;w++){
            //compute mean and var
            num_of_pixs = 0;
            mean=0.0;
            var=0.0;
            for(lh=h-hlf_ht;lh<=h+hlf_ht;lh++){
                for(lw=w-hlf_wt;lw<=w+hlf_wt;lw++){
                    if(lh>=0 && lh<trgt_map_yuv->ht && lw>=0 && lw<trgt_map_yuv->wt){
                        mean+=trgt_map_yuv->y[lh][lw];
                        num_of_pixs++;
                    }
                }
            }
            mean/=(double)num_of_pixs;

            num_of_pixs = 0;
            for(lh=h-hlf_ht;lh<=h+hlf_ht;lh++){
                for(lw=w-hlf_wt;lw<=w+hlf_wt;lw++){
                    if(lh>=0 && lh<trgt_map_yuv->ht && lw>=0 && lw<trgt_map_yuv->wt){
                        var+=(trgt_map_yuv->y[lh][lw]-mean)*(trgt_map_yuv->y[lh][lw]-mean);
                        num_of_pixs++;
                    }
                }
            }
            var/=(double)num_of_pixs;

            indx=match_get_index(smpls,mean,var);
            trgt_map_yuv->u[h][w]=smpls->elm[indx].u;
            trgt_map_yuv->v[h][w]=smpls->elm[indx].v;
        }
    }

    struct map_rgb_t *out_map_rgb = map_yuv_to_rgb(trgt_map_yuv);
    struct img_rgb_t *out_img_rgb = map_to_img_rgb(out_map_rgb);

    arry_smpl_destruct(smpls);
    map_rgb_destruct(trgt_map_rgb);
    map_yuv_destruct(trgt_map_yuv);
    map_rgb_destruct(out_map_rgb);

    return out_img_rgb;
}

#include  "include/image.h"

unsigned long match_get_index(struct arry_smpl_t *smpls, double target_ym, double target_yv)
{
    unsigned long n,index;
    double d,d_min;

    index=0;
    d_min=(target_ym-smpls->elm[0].ym)*(target_ym-smpls->elm[0].ym) + (sqrt(target_yv)-sqrt(smpls->elm[0].yv))*(sqrt(target_yv)-sqrt(smpls->elm[0].yv));
    for(n=0;n<smpls->num_of_smpls;n++) {
        d=(target_ym-smpls->elm[n].ym)*(target_ym-smpls->elm[n].ym) + (sqrt(target_yv)-sqrt(smpls->elm[n].yv))*(sqrt(target_yv)-sqrt(smpls->elm[n].yv));
        if(d<d_min) {
            d_min=d;
            index=n;
        }
    }

    return index;
}

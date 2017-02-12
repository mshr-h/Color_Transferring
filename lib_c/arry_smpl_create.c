#include  "include/image.h"

struct arry_smpl_t *arry_smpl_create(unsigned long num_of_smpls)
{
    struct arry_smpl_t *out;

    out=(struct arry_smpl_t *)malloc(sizeof(struct arry_smpl_t));

    out->elm=(struct smpl_t *)malloc((num_of_smpls)*sizeof(struct smpl_t));
    if(out->elm==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
      exit(-1);
    }
    out->num_of_smpls=num_of_smpls;

    return out;
}

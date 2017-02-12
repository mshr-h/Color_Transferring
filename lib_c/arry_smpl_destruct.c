#include  "include/image.h"

void arry_smpl_destruct(struct arry_smpl_t *arry_smpl)
{
    free(arry_smpl->elm);
    free(arry_smpl);
}

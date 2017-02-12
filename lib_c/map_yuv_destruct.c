#include  "include/image.h"

void map_yuv_destruct(struct map_yuv_t *map)
{
	free(map->y[0]); free(map->y);
	free(map->u[0]); free(map->u);
	free(map->v[0]); free(map->v);

	free(map);
}

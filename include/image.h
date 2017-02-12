#ifndef IMAGE_H
#define IMAGE_H

#define NUM_OF_SMPLS   1000
#define SMPLS_INTERVAL 7//pixs

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct img_t
{
    int wt;
    int ht;
    unsigned char **data;
};

struct img_rgb_t
{
    int wt;
    int ht;

    unsigned char **r;
    unsigned char **g;
    unsigned char **b;
};

struct img_yuv_t
{
    int wt;
    int ht;

    unsigned char **y;
    unsigned char **u;
    unsigned char **v;
};

struct map_t
{
    int wt;
    int ht;
    double **data;
};

struct map_rgb_t
{
    int wt;
    int ht;
    double **r;
    double **g;
    double **b;
};

struct map_yuv_t
{
    int wt;
    int ht;
    double **y;
    double **u;
    double **v;
    double ym;
    double yv;
};

struct smpl_t
{
    int w;
    int h;
    double y;
    double u;
    double v;

    double ym;//mean
    double yv;//variance
};

struct arry_smpl_t
{
    unsigned long num_of_smpls;
    struct smpl_t *elm;
};

// function prototype
#ifdef __cplusplus
extern "C" {
#endif

unsigned char **
Malloc2D_uchr
(
    int wt,
    int ht,
    unsigned char init
);

double **
Malloc2D_dbl
(
    int wt,
    int ht,
    double init
);

struct img_rgb_t *
img_rgb_create
(
    int wt,
    int ht,
    unsigned char init
);

void
img_rgb_destruct
(
    struct img_rgb_t *img
);

struct map_t *
map_create
(
    int wt,
    int ht,
    double init
);

void
map_destruct
(
    struct map_t *map
);

struct map_rgb_t *
map_rgb_create
(
    int wt,
    int ht,
    double init
);

void
map_rgb_destruct
(
    struct map_rgb_t *map
);

struct map_yuv_t *
map_yuv_create
(
    int wt,
    int ht,
    double init
);

void
map_yuv_destruct
(
    struct map_yuv_t *map
);

struct map_rgb_t *
img_to_map_rgb
(
    struct img_rgb_t *in
);

struct img_rgb_t *
map_to_img_rgb
(
    struct map_rgb_t *map
);

struct map_yuv_t *
map_rgb_to_yuv
(
    struct map_rgb_t *in
);

struct map_rgb_t *
map_yuv_to_rgb
(
    struct map_yuv_t *in
);

struct arry_smpl_t *
arry_smpl_create
(
    unsigned long num_of_smpls
);

void
arry_smpl_destruct
(
    struct arry_smpl_t *arry_smpl
);

struct arry_smpl_t *
generate_regular_samples
(
    struct img_rgb_t *src_rgb,
    struct img_rgb_t *trgt_rgb,
    int wnd_ht,
    int wnd_wt
);

void
map_yuv_set_mean_and_var
(
    struct map_yuv_t *map
);

void luminance_remapping
(
    struct map_yuv_t *src,
    struct map_yuv_t *target
);

unsigned long
match_get_index
(
    struct arry_smpl_t *smpls,
    double target_ym,
    double target_yv
);

struct img_rgb_t *transfer_color
(
    struct img_rgb_t *trgt,
    struct img_rgb_t *src,
    int wnd_ht,
    int wnd_wt
);

#ifdef __cplusplus
}
#endif

#endif // IMAGE_H

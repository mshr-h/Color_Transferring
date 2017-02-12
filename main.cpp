#include "include/image.h"
#include "include/image_qt.h"

int main(int argc, char *argv[])
{
    if(argc != 4) {
        printf("./Color_Transferring target.png source.png out.png\n");
        return 1;
    }

    struct img_rgb_t *target = QImage_to_img_rgb(new QImage(argv[1]));
    struct img_rgb_t *source = QImage_to_img_rgb(new QImage(argv[2]));

    int wnd_ht = 5; // size of local windows
    int wnd_wt = 5; // size of local windows
    struct img_rgb_t *out = transfer_color(target, source, wnd_ht, wnd_wt);

    QImage outImg = img_rgb_to_QImage(out);

    outImg.save(argv[3], "PNG");

    img_rgb_destruct(target);
    img_rgb_destruct(source);
    img_rgb_destruct(out);

    return 0;
}

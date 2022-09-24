/*
=> Derleme:

Linux: gcc example-05.c libmlx_linux.a -lXext -lX11 -lm -lz
Macos: gcc example-05.c libmlx_macos.a -framework OpenGL -framework AppKit

Açıklama: example-04 de boş resmin içini doldurmuştuk bu örnekte var olan resmin renk kodlarında düzenleme yapıcaz.
Basit örnek olması açısından ben gelen resmin her x'in indeks bakımından çift olanlara mavi tonlarından bir renk bastım.
*/

# include "mlx.h"
# include <stdio.h>

int main(void)
{
        int width;
        int height;
        int bits_per_pixel;
        int size_line;
        int endian;

        void *mlx_ptr = mlx_init();
        void *win_ptr = mlx_new_window(mlx_ptr, 1500, 750, "Deneme");
        void *img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./wall.xpm", &width, &height);

        if (img_ptr == NULL)
        {
                printf("Xpm dosyası verilen konumda bulunamadı.\n");
                return (1);
        }
        int *img_data = (int *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);


        int x;
        int y = 0;
        while (y <= 64)
        {
                x = 0;
                while (x <= 64)
                {
                        img_data[x + (y * 64)] = 33023;
                        x+=2;
                }
                y++;
        }
        
        mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 10, 10);
        mlx_loop(mlx_ptr);
        return (0);
}
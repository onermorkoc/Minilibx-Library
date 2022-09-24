/*
=> Derleme:

Linux: gcc example-01.c libmlx_linux.a -lXext -lX11 -lm -lz
Macos: gcc example-01.c libmlx_macos.a -framework OpenGL -framework AppKit

==> mlx_pixel_put() Fonksiyonu <==

Kabaca pencerenin istenilen pixel konumuna(x, y) verilen rengi(int bir renk kodu) koyuyor. Parametre olarak
mlx_ptr, win_ptr, rengin koyulacak pixel konumu için x, y ve son olarak koyulacak renk kodu (int)
Aşagıdaki örnekte iç içe 2 while ile pencerenin her pixel konumuna açık mavi bir renk bastım
Farklı renk int kodları denemek için bu siteye göz atınız: https://www.tydac.ch/color/
*/

# include "mlx.h"

int main(void)
{
        void *mlx_ptr = mlx_init();
        void *win_ptr = mlx_new_window(mlx_ptr, 1500, 750, "Deneme");

        int x;
        int y = 0;

        while (y <= 750)
        {
                x = 0;
                while (x <= 1500)
                {
                        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 5353205);
                        x++;
                }
                y++;
        }
        mlx_loop(mlx_ptr); 
        return (0);
}
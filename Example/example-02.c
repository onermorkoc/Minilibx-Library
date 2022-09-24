/*
=> Derleme:

Linux: gcc example-02.c libmlx_linux.a -lXext -lX11 -lm -lz
Macos: gcc example-02.c libmlx_macos.a -framework OpenGL -framework AppKit

==> mlx_string_put() Fonksiyonu <==

Pencereye yazı basmanıza olanak sağlayan fonksiyondur. Parametre olarak sırasıyla
mlx_ptr, win_ptr, yazının basılacak konumu (x, y), yazının rengi (int olarak) ve
basıtılacak yazı (const char dizi olarak).

Not: Yazının boyutu 10 oldugu için y değerini 10 dan büyük bir değer veriniz.

Farklı renk int kodları denemek için bu siteye göz atınız: https://www.tydac.ch/color/
*/

# include "mlx.h"

int main(void)
{
        void *mlx_ptr = mlx_init();
        void *win_ptr = mlx_new_window(mlx_ptr, 1500, 750, "Deneme");

        mlx_string_put(mlx_ptr, win_ptr, 50, 50, 16777215, "Hello World!");

        mlx_loop(mlx_ptr);
        return (0);
}
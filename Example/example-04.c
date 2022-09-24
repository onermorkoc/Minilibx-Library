/*
=> Derleme:

Linux: gcc example-04.c libmlx_linux.a -lXext -lX11 -lm -lz
Macos: gcc example-04.c libmlx_macos.a -framework OpenGL -framework AppKit

==> mlx_new_image() Fonksiyonu <==

Açıklama: İçi boş(siyah) resim oluşturur parametre olarak mlx_ptr, oluşacak resim genişligi(width) ve oluşacak resmin yüksekliği (height) alıyor. 
Eger resmi başarılı bir şekilde oluştursa bize void *img_ptr döndürür.

==> mlx_get_data_addr() Fonksiyonu <==

int *img_data = (int *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian)

Açıklama: Diyelimki bir resim oluşturduk peki resmin içindeki pixellere nasıl ulaşıcaz içini nasıl doldurcaz hepsini mlx_get_data_addr fonksiyondan 
dönen int diziden yapıyoruz bu fonksiyon hem bir resim hakkında bilgi verir hemde resmin pixel pixel datasını bize dizi olarak döndürür.Öncelikle
parametre olarak resmin adresini alır(img_ptr), daha sonra bu resim hakkında bilgilerini gelen parametrelerın ıcıne aktarmak için bits_per_pixel,
size_line ve endian degişkenlerinin (3 de int türünden olmalı) adresslerini gönderiyoruz(basına & koyarsanız o degişkenin adresini göndermiş oluruz)
daha sonra bize dönen int *img_data nın diyelimki 0. pixel renk kodunu kırmızı yapıcaz yapıcagımız işlem şu: img_data[0] = FF0000; eger resmin full
kırmızı olmasını ıstıyorsak whıle ile içini donup tek tek pıxel koduna kırmızı degerini vermemız gerekırdı.

*/

# include "mlx.h"

int main(void)
{
        void *mlx_ptr = mlx_init();
        void *win_ptr = mlx_new_window(mlx_ptr, 1500, 750, "Deneme");

        void *new_img = mlx_new_image(mlx_ptr, 300, 300);

        int bits_per_pixel;
        int size_line;
        int endian;
        int *new_img_data = (int *)mlx_get_data_addr(new_img, &bits_per_pixel, &size_line, &endian);

        int x;
        int y = 0;

        while (y <= 300)
        {
                x = 0;
                while (x <= 300)
                {
                        new_img_data[x + (y * 300)] = 5353205;
                        x++;
                }
                y++;
        }
        mlx_put_image_to_window(mlx_ptr, win_ptr, new_img, 0, 0);
        mlx_loop(mlx_ptr);
        return (0);
}
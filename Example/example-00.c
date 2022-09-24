/*
=> Derleme:

Linux: gcc example-00.c libmlx_linux.a -lXext -lX11 -lm -lz
Macos: gcc example-00.c libmlx_macos.a -framework OpenGL -framework AppKit

*/

# include "mlx.h"
# include <stdio.h>
# include <unistd.h>

int main(void)
{
	/* ==> mlx_init() Fonksiyonu <==

	Minilibx kütüphanesini başlatıyor ve void bir pointer döndürüyor. Dönen void pointerı
	neredeyse kütüphanenin tüm fonksıyonlara parametre olarak yolluyoruz.

	*/
	void *mlx_ptr = mlx_init();




	/* ==> mlx_new_window() Fonsiyonu <==

	Siyah içi boş bir pencere oluşturuyor. Parametre olarak mlx_ptr, pencerenin genişliği için ise int width,
	yüksekliği için int height alıyor. Son olarak da pencere adı alıyor(const char bir dizi olarak) ve 
	bize void bir win_ptr pointer döndürüyor. mlx_ptr gibi hemen hemen kütüphanenin tüm fonksiyonlara
	parametre olarak yolluyoruz.

	*/
	void *win_ptr = mlx_new_window(mlx_ptr, 1500, 750, "Deneme");




	/* ==> mlx_xpm_file_to_image() Fonksiyonu <==

	xmp uzantılı resimleri okuyor ve bir pointer döndürüyor (dönen pointeri ekrana basması için mlx_put_image_to_window() fonksiyona parametre olarak yollucağız)
	Parametre olarak mlx_ptr, xpm dosyasının konumu ve iki tane değeri verilmemiş int adresi istiyor. Eğer okuyamazsa null döndürüyor. Resimler genellikle png veya jpg
	olur xpm çevirmek için bu siteyi kullanabilirsiniz: https://convertio.co/tr/png-xpm/

	*/
	int     width;
	int     height;

	void *img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./wall.xpm", &width, &height);

	if (img_ptr == NULL)
	{
		printf ("Xpm dosyası verilen konumda bulunamadı");
		return (1);
	}




	/* ==> mlx_put_image_to_window() Fonsiyonu <==

	Resimlerı ekrana basmamıza yarıyor. Parametre olarak mlx_ptr, win_ptr, img_ptr ve resmin pencerenin hangi konuma basılacagını belirtmek için
	bir x y kordınatı alıyor örnek olarak : (0, 0) noktası verelim

	*/
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);




	/* ==> mlx_clear_window() Fonksiyonu <==

	Pencereye basılmıs tüm resimleri, pixelleri temizliyor parametre olarak mlx_ptr ve win_ptr alıyor.

	*/
	write(1, "2 saniye içinde pencere temizlenecek...\n", 41);
	sleep(2);
	mlx_clear_window(mlx_ptr, win_ptr);




	/* ==> mlx_destroy_window() Fonksiyonu

	Pencereyi yok ediyor parametre olarak mlx_ptr ve win_ptr alıyor.

	*/
	write(1, "2 saniye içinde pencere yok edilecek...\n", 41);
	sleep(2);
	mlx_destroy_window(mlx_ptr, win_ptr);




	/* ==> mlx_destroy_image() Fonksiyonu

	Resmi yok eder (freeler). Parametre olarak mlx_ptr ve resmin pointeri yani img_ptr alır.

	*/
	write(1, "2 saniye içinde resim yok edilecek...\n", 39);
	sleep(2);
	mlx_destroy_image(mlx_ptr, img_ptr);




	/* ==> mlx_destroy_display() Fonksiyonu <==

	Kütüphaneyi freelemek için kullanılır. Parametre olarak mlx_ptr alıyor.

	*/
	write(1, "2 saniye içinde kütüphane freelenecek...\n", 44);
	sleep(2);
	mlx_destroy_display(mlx_ptr);




	/* ==> mlx_loop Fonksiyonu <==

	Pencerenin açık kalmasını sağlıyor. Parametre olarak mlx_ptr alıyor.

	*/
	mlx_loop(mlx_ptr);

	return (0);
}

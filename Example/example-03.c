/*
=> Derleme:

Linux: gcc example-03.c libmlx_linux.a -lXext -lX11 -lm -lz
Macos: gcc example-03.c libmlx_macos.a -framework OpenGL -framework AppKit

==> mlx_hook() Fonksiyonu <==

Açıklama: Fonksiyon girilen parametrelere göre klayvenin kontrolüne ve pencere de bulunan çarpı(x) butonunu kontrol etmemize
olanak sağlar.

mlx_hook(win_ptr, 17, 0, fonksiyon, struct_dizi) ==> Pencereden çarpı(x) butonunu kontrol eder parametre olarak win_ptr,
"17, 0" degerleri sabit, int döndüren bir fonksiyon ve bir sonraki parametre ise önceki parametre olarak verdigimiz 
fonksiyonun parametresini veriyoruz (o fonksıyonun kaynagını daha doğrusu. Aşagıdaki örneği inceleyiniz daha anlaşılır olacaktır) 

mlx_hook(win_ptr, 2, 1L << 0, fonksiyon, struct_dizi) ==> Klayveyi kontrol eder parametre olarak win_ptr, "2, 1L << 0" değerleri sabit ve
int döndüren int bir parametre alan (çünkü klayvede basılan her tuşun int bir karşılığı var bunları fonksiyon içinde kontrol etmek için)
fonksiyon, bide bu fonksiyonun kaynagını veriyoruz(yukardaki açıklamayla aynı ek olarak dıyelımkı fonksıyon dısardan herhangı bır kaynak parametre almıyorsa
NULL yazıyoruz)

Bazı klayve tuşların key kodların linux ve macos için degerleri:

W tuşu      => Linux: 119  Macos: 13
S tuşu      => Linux: 115  Macos: 1
D tuşu      => Linux: 100  Macos: 2
A tuşu      => Linux: 97   Macos: 0
Sol tuşu    => Linux: 65361  Macos: 123 
Sağ tuşu    => Linux: 65363  Macos: 124  
Yukarı tuşu => Linux: 65362  Macos: 126 
Aşağı tuşu  => Linux: 65364  Macos: 125 
Esc tuşu    => Linux: 65307  Macos: 53   

*/

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data // kaynak
{
        void *mlx_ptr;
        void *win_ptr;
}t_data;


int keyboard(int keycode, t_data *s_data)
{
        //printf("Basılan klayve tuşunun key code: %d\n", keycode);

        if (keycode == 119 || keycode == 13)
               printf("W tuşuna basıldı.\n");
        else if (keycode == 115 || keycode == 1)
                printf("S tuşuna basıldı.\n");
        else if (keycode == 100 || keycode == 2)
                printf("D tuşuna basıldı.\n");
        else if (keycode == 97 || keycode == 0)
                printf("A tuşuna basıldı.\n");
        else if (keycode == 53 || keycode == 65307)
                printf("ESC tuşuna basıldı.\n");
        return (0);
}

int shutdown(t_data *s_data)
{
        printf("Pencerenin çarpı(x) tuşuna basıldı.\n");
        exit(0);
}

int main(void)
{
        t_data s_data;

        s_data.mlx_ptr = mlx_init();
        s_data.win_ptr = mlx_new_window(s_data.mlx_ptr, 1500, 750, "Deneme");

        mlx_hook(s_data.win_ptr, 2, 1L << 0, keyboard, &s_data);
        mlx_hook(s_data.win_ptr, 17, 0, shutdown, &s_data);

        mlx_loop(s_data.mlx_ptr);
        return (0);
}

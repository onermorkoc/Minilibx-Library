# Minilibx-Kütüphanesi Hakkında

[42 okul](https://www.42istanbul.com.tr/) projelerinde kullanılan minilibx kütüphanesinin hem linux hem macos için nasıl kullanıldığını nasıl derleme alınacağını ve fonksiyonların ne iş yaptığını açıklayan Türkçe bir klavuz.

Kütüphaneyi kendi projenize dahil edin ve derleme alın: [Minilibx-Notlar](https://github.com/onermorkoc/Minilibx-Kutuphanesi/blob/main/Minilibx-Notlar.txt)

➡️ [example-00](https://github.com/onermorkoc/Minilibx-Kutuphanesi/blob/main/Example/example-00.c): Kütüphaneyi başlatın, pencere oluşturun ve resim basın.
```
mlx_init()
mlx_new_window()
mlx_xpm_file_to_image()
mlx_put_image_to_window()
mlx_clear_window()
mlx_destroy_window()
mlx_destroy_image()
mlx_destroy_display()
mlx_loop
```
➡️ [example-01](https://github.com/onermorkoc/Minilibx-Kutuphanesi/blob/main/Example/example-01.c): Ekrana bir pixel renk koyun.
```
mlx_pixel_put()
```
➡️ [example-02](https://github.com/onermorkoc/Minilibx-Kutuphanesi/blob/main/Example/example-02.c): Ekrana yazı basın.
```
mlx_string_put()
```
➡️ [example-03](https://github.com/onermorkoc/Minilibx-Kutuphanesi/blob/main/Example/example-03.c): Klayveyi kontrol edin.
```
mlx_hook
```
➡️ [example-04](https://github.com/onermorkoc/Minilibx-Kutuphanesi/blob/main/Example/example-04.c): Resim oluşturun ve içini doldurun.
```
mlx_new_image()
mlx_get_data_addr()
```
➡️ [example-05](https://github.com/onermorkoc/Minilibx-Kutuphanesi/blob/main/Example/example-05.c): Var olan resmi düzenleyin.
```
mlx_new_image()
mlx_get_data_addr()
```

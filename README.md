
Реализация консольного приложения, позволяющая применять к изображениям различные фильтры, аналогичные фильтрам в популярных графических редакторах
Пример работы будет рассматриваться на примере фотографии:

Описание формата аргументов командной строки:
{имя программы} {путь к входному файлу} {путь к выходному файлу} [-{имя фильтра 1} [параметр фильтра 1] [параметр фильтра 2] ...] [-{имя фильтра 2} [параметр фильтра 1] [параметр фильтра 2] ...] ...
При запуске без аргументов программа выводит справку.

Пример
./image_processor input.bmp /tmp/output.bmp -crop 800 600 -gs -blur 0.5

Фильтры
Crop (-crop width height)
Обрезает изображение до заданных ширины и высоты. Используется верхняя левая часть изображения.
Если запрошенные ширина или высота превышают размеры исходного изображения, выдается доступная часть изображения.
![lenna](https://github.com/Avilon1111/image_processor/assets/165182637/7e80dd93-78ab-40d1-ab59-82bb32ffee4c)

Grayscale (-gs)
Преобразует изображение в оттенки серого
![result](https://github.com/Avilon1111/image_processor/assets/165182637/c05ac993-2104-4ae8-9206-40f3d162482a)


Negative (-neg)
Преобразует изображение в негатив
![result (1)](https://github.com/Avilon1111/image_processor/assets/165182637/3c2f89db-7fe6-4470-9acf-78a64fc95121)


Sharpening (-sharp)
Повышение резкости
![result (2)](https://github.com/Avilon1111/image_processor/assets/165182637/33e756ef-fe06-48f3-9d26-a1f74813fd19)


Edge Detection (-edge threshold)
Выделение границ. В примере параметр threshold = 0.1
![result (3)](https://github.com/Avilon1111/image_processor/assets/165182637/4ce4da1f-3991-40e6-ae88-1e9fdea2df90)


Gaussian Blur (-blur sigma). В примере sigma = 7.5
![result (4)](https://github.com/Avilon1111/image_processor/assets/165182637/9162f449-8159-4518-b17a-8d7670e01145)

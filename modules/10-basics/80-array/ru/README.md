<div style="padding:62.5% 0 0 0;position:relative;"><iframe src="https://player.vimeo.com/video/128854222?badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" referrerpolicy="strict-origin-when-cross-origin" style="position:absolute;top:0;left:0;width:100%;height:100%;" title="8 Массивы в Си"></iframe></div><script src="https://player.vimeo.com/api/player.js"></script>

## Массивы

В этом уроке знакомимся с массивами в C.

Обычные переменные удобны, когда значений немного. Но если нужно хранить много однотипных данных, лучше использовать массив.

## Что такое массив

Массив — это набор элементов одного типа, расположенных подряд в памяти.

Пример:

```c
int arr[4];
```

- Тип `int` задает тип элементов массива.
- Число `4` задает количество элементов.

Важный момент: индексация начинается с нуля.

Для массива из 4 элементов допустимые индексы:

- Индекс `0`.
- Индекс `1`.
- Индекс `2`.
- Индекс `3`.

## Заполнение массива

```c
arr[0] = 32;
arr[1] = 12;
arr[2] = 42;
arr[3] = 99;
```

Обращаемся к каждому элементу по индексу в квадратных скобках.

## Сумма элементов через цикл

Главное преимущество массива видно в цикле: можно обработать все элементы одинаково.

```c
int i;
int sum;

sum = 0;
for (i = 0; i < 4; i++)
  sum = sum + arr[i];
```

## Полная программа

```c
#include <stdio.h>

int main(void)
{
  int arr[4];
  int i;
  int sum;

  arr[0] = 32;
  arr[1] = 12;
  arr[2] = 42;
  arr[3] = 99;

  sum = 0;
  for (i = 0; i < 4; i++)
    sum = sum + arr[i];

  printf("%d\n", sum);
  return 0;
}
```

Результат:

```text
185
```

## Итоги

- Массив хранит набор значений одного типа.
- Индексы начинаются с `0`.
- Циклы позволяют удобно обрабатывать все элементы массива.

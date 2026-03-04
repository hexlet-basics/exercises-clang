<div style="padding:62.5% 0 0 0;position:relative;"><iframe src="https://player.vimeo.com/video/128853336?badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" referrerpolicy="strict-origin-when-cross-origin" style="position:absolute;top:0;left:0;width:100%;height:100%;" title="2 Переменные и циклы в Си"></iframe></div><script src="https://player.vimeo.com/api/player.js"></script>

## Переменные и цикл while

В этом уроке соберем первую полезную программу: таблицу перевода температуры из градусов Фаренгейта в градусы Цельсия.

Идея простая: берем значение в Фаренгейтах, считаем по формуле и печатаем результат.

Формула:

```text
C = 5 * (F - 32) / 9
```

## Переменные

В C переменная имеет тип. Если переменная объявлена как `int`, в ней хранятся только целые числа.

```c
int fahr;
int celsius;
int lower;
int upper;
int step;
```

Зададим стартовые значения:

```c
lower = 0;
upper = 300;
step = 20;
fahr = lower;
```

## Вывод через printf()

Чтобы печатать целые числа, используем `%d`:

```c
printf("%d : %d\n", fahr, celsius);
```

- В первый `%d` подставится значение `fahr`.
- Во второй `%d` подставится значение `celsius`.
- Последовательность `\n` переводит строку.

## Повторение через цикл while

Нам нужна не одна строка, а целая таблица. Для этого используем цикл `while`: код повторяется, пока условие истинно.

Полная программа:

```c
#include <stdio.h>

int main(void)
{
  int fahr;
  int celsius;
  int lower;
  int upper;
  int step;

  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;

  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d : %d\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
```

## Итоги

- Переменные хранят данные во время работы программы.
- Тип `int` подходит для целых значений.
- `printf()` умеет подставлять значения переменных в строку.
- Цикл `while` позволяет повторять код, пока выполняется условие.

<div style="padding:62.5% 0 0 0;position:relative;"><iframe src="https://player.vimeo.com/video/128853337?badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" referrerpolicy="strict-origin-when-cross-origin" style="position:absolute;top:0;left:0;width:100%;height:100%;" title="3 FLOAT в Си"></iframe></div><script src="https://player.vimeo.com/api/player.js"></script>

## Тип float

В прошлом уроке мы вывели таблицу перевода температур, но у нее были две проблемы:

1. Значения в столбцах выглядели неровно.
2. Расчеты были неточными, потому что использовались только целые числа (`int`).

В этом уроке исправим обе.

## Почему int недостаточно

Формула перевода:

```text
C = (5 / 9) * (F - 32)
```

Для `F = 0` правильный результат примерно `-17.78`, а не `-17`. Чтобы получить дробную часть, нужно перейти на тип `float`.

## Переход на float

Меняем тип рабочих переменных:

```c
float fahr;
float celsius;
float lower;
float upper;
float step;
```

Значения тоже удобно записывать как дробные:

```c
lower = 0.0;
upper = 300.0;
step = 20.0;
fahr = lower;
```

## Точная формула

С `float` можно безопасно использовать дробные коэффициенты:

```c
celsius = (5.0 / 9.0) * (fahr - 32.0);
```

Так выражение считается в вещественной арифметике, без потери точности на целочисленном делении.

## Форматирование вывода

Для `float` в `printf()` используем `%f`. Можно сразу задать ширину поля и количество знаков после запятой:

```c
printf("%6.2f : %6.2f\n", fahr, celsius);
```

- Значение `6` задает минимальную ширину поля.
- Значение `.2` задает два знака после запятой.
- Спецификатор `f` указывает на вещественное число.

## Полная программа

```c
#include <stdio.h>

int main(void)
{
  float fahr;
  float celsius;
  float lower;
  float upper;
  float step;

  lower = 0.0;
  upper = 300.0;
  step = 20.0;
  fahr = lower;

  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%6.2f : %6.2f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
```

## Итоги

- Тип `float` нужен, когда важна дробная часть.
- Формат `%6.2f` помогает выравнивать таблицу и ограничивать число знаков после запятой.
- Вычисления с `float` дают более точный результат, чем с `int` в этой задаче.

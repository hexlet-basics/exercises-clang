<div style="padding:62.5% 0 0 0;position:relative;"><iframe src="https://player.vimeo.com/video/128853339?badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" referrerpolicy="strict-origin-when-cross-origin" style="position:absolute;top:0;left:0;width:100%;height:100%;" title="4 Цикл FOR в Си"></iframe></div><script src="https://player.vimeo.com/api/player.js"></script>

## Цикл for

В этом уроке перепишем таблицу перевода температур, но вместо `while` используем цикл `for`.

Результат будет тем же, изменится только форма записи цикла.

## Как устроен цикл for

Заголовок цикла состоит из трех частей:

```c
for (начало; условие; шаг)
```

В нашей задаче это выглядит так:

```c
for (fahr = 0.0; fahr <= 300.0; fahr = fahr + 20.0)
```

- Выражение `fahr = 0.0` задает начальное значение.
- Условие `fahr <= 300.0` определяет, когда цикл выполняется.
- Выражение `fahr = fahr + 20.0` задает шаг после каждой итерации.

## Вычисление прямо в printf

Формулу можно сначала сохранить в переменную, а можно посчитать прямо в `printf()`. Оба варианта корректны.

```c
printf("%6.2f : %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
```

## Полная программа

```c
#include <stdio.h>

int main(void)
{
  float fahr;

  for (fahr = 0.0; fahr <= 300.0; fahr = fahr + 20.0)
    printf("%6.2f : %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));

  return 0;
}
```

Таблица на выходе будет такой же, как в версии с `while`.

## Итоги

- Цикл `for` особенно удобен, когда старт, условие и шаг можно записать в одном месте.
- Вычисление можно передавать в `printf()` напрямую, без промежуточной переменной.

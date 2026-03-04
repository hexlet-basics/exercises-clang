<div style="padding:62.5% 0 0 0;position:relative;"><iframe src="https://player.vimeo.com/video/128853340?badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" referrerpolicy="strict-origin-when-cross-origin" style="position:absolute;top:0;left:0;width:100%;height:100%;" title="5 Функции в Си"></iframe></div><script src="https://player.vimeo.com/api/player.js"></script>

## Функции

В этом уроке напишем свою функцию и разберем, как ее вызывать из `main()`.

Идея простая: сделаем функцию `power()`, которая возводит число в целую неотрицательную степень.

```c
int power(int base, int n)
{
  int i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;

  return p;
}
```

## Что здесь важно

- Объявление `int power(int base, int n)` задает функцию с двумя параметрами.
- Параметр `base` задает основание степени.
- Параметр `n` задает показатель степени.
- Инструкция `return p;` возвращает результат вычисления.

Чтобы `main()` могла вызвать функцию, удобно заранее объявить ее прототип:

```c
int power(int base, int n);
```

## Полная программа

```c
#include <stdio.h>

int power(int base, int n);

int main(void)
{
  printf("%d\n", power(2, 10));
  return 0;
}

int power(int base, int n)
{
  int i;
  int p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;

  return p;
}
```

Ожидаемый вывод:

```text
1024
```

Если заменить вызов на `power(3, 12)`, получите `531441`.

## Итоги

- Функция помогает вынести повторяемую логику в отдельный блок.
- У функции есть параметры и возвращаемое значение.
- Прототип сообщает компилятору сигнатуру функции до ее использования.
- `main()` обычно завершается `return 0;`, если программа отработала без ошибок.

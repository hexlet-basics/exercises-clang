<div style="padding:62.5% 0 0 0;position:relative;"><iframe src="https://player.vimeo.com/video/128854221?badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" referrerpolicy="strict-origin-when-cross-origin" style="position:absolute;top:0;left:0;width:100%;height:100%;" title="6 IF/ELSE и комментарии в Си"></iframe></div><script src="https://player.vimeo.com/api/player.js"></script>

## Условие if else

В этом уроке разбираем условные конструкции `if/else` и применяем их в функции `power()`.

Заодно закрываем важную деталь: у `main()` тоже должен быть тип и возвращаемое значение.

```c
int main(void)
{
  return 0;
}
```

`0` обычно означает, что программа завершилась без ошибок.

## Комментарии

Комментарии помогают объяснить код людям. Компилятор их игнорирует.

Однострочный комментарий:

```c
// this function calculates base to the power of n
```

Многострочный комментарий:

```c
/*
  this function calculates
  base to the power of n
*/
```

## Условие if else

Добавим в `power()` правило: если основание отрицательное, функция сразу возвращает `0`.

```c
int power(int base, int n)
{
  int i;
  int p;

  if (base < 0)
    return 0;
  else {
    p = 1;
    for (i = 1; i <= n; i++)
      p = p * base;

    return p;
  }
}
```

Логика простая:

- Если `base < 0`, выполняется ветка `if`.
- Иначе выполняется ветка `else` и считается степень.

## Полная программа

```c
#include <stdio.h>

int power(int base, int n);

int main(void)
{
  printf("%d\n", power(3, 4));
  printf("%d\n", power(-3, 4));
  return 0;
}

int power(int base, int n)
{
  int i;
  int p;

  if (base < 0)
    return 0;
  else {
    p = 1;
    for (i = 1; i <= n; i++)
      p = p * base;

    return p;
  }
}
```

Результат:

- Вызов `power(3, 4)` возвращает `81`.
- Вызов `power(-3, 4)` возвращает `0` по нашему правилу.

## Итоги

- Конструкция `if/else` позволяет явно задать разные сценарии выполнения кода.
- Функция `main()` должна иметь корректный тип и возвращать код завершения.
- Комментарии помогают читать код, но не влияют на выполнение.

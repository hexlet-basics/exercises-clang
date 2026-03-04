<div style="padding:62.5% 0 0 0;position:relative;"><iframe src="https://player.vimeo.com/video/128854220?badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" referrerpolicy="strict-origin-when-cross-origin" style="position:absolute;top:0;left:0;width:100%;height:100%;" title="7 SWITCH вместо IF/ELSE в Си"></iframe></div><script src="https://player.vimeo.com/api/player.js"></script>
## Switch

В этом уроке разберем, как заменить длинную цепочку `if/else if/else` на `switch`.

Для примера возьмем функцию `charcode()`, которая получает символ и возвращает код:

- Для символа `'a'` функция возвращает `0`.
- Для символа `'b'` функция возвращает `1`.
- Для любого другого символа функция возвращает `3`.

## Вариант через if else if else

```c
int charcode(char c)
{
  if (c == 'a')
    return 0;
  else if (c == 'b')
    return 1;
  else
    return 3;
}
```

Здесь важно:

- Для сравнения используем `==`, а не `=`.
- Оператор `=` выполняет присваивание.
- Оператор `!=` означает "не равно".

## Вариант через switch

```c
int charcode(char c)
{
  switch (c) {
    case 'a':
      return 0;
    case 'b':
      return 1;
    default:
      return 3;
  }
}
```

Ключевое слово `case` задает отдельные варианты, а `default` задает ветку для всех остальных значений.

## Почему важен break

В `switch` есть важная особенность: если не поставить `break`, выполнение "проваливается" в следующий `case`.

Пример с ошибкой:

```c
int charcode(char c)
{
  int p;

  switch (c) {
    case 'a':
      p = 0;
    case 'b':
      p = 1;
    default:
      p = 3;
  }

  return p;
}
```

Если передать `'a'`, результатом все равно станет `3`, потому что выполнятся все ветки подряд.

Правильный вариант:

```c
int charcode(char c)
{
  int p;

  switch (c) {
    case 'a':
      p = 0;
      break;
    case 'b':
      p = 1;
      break;
    default:
      p = 3;
      break;
  }

  return p;
}
```

Теперь поведение корректное:

- Для символа `'a'` функция возвращает `0`.
- Для символа `'b'` функция возвращает `1`.
- Для любого другого символа функция возвращает `3`.

## Итоги

- Конструкция `switch` удобна для выбора из нескольких конкретных значений.
- Почти в каждом `case` нужен `break`, чтобы не было fallthrough.
- Ветка `default` покрывает все остальные значения.

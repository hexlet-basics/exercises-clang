<div style="padding:62.5% 0 0 0;position:relative;"><iframe src="https://player.vimeo.com/video/128853333?badge=0&amp;autopause=0&amp;player_id=0&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture; clipboard-write; encrypted-media; web-share" referrerpolicy="strict-origin-when-cross-origin" style="position:absolute;top:0;left:0;width:100%;height:100%;" title="Первая программа на Си"></iframe></div><script src="https://player.vimeo.com/api/player.js"></script>

## Первая программа

В этом уроке мы напишем первую программу на C и сразу пройдем полный цикл: код -> компиляция -> запуск.

Классический старт — `Hello, World!`.

```c
#include <stdio.h>

int main(void)
{
  printf("Hello, World!\n");
  return 0;
}
```

## Что здесь происходит

- `#include <stdio.h>` подключает стандартную библиотеку ввода-вывода, чтобы мы могли использовать `printf()`.
- `main()` — точка входа в программу. Выполнение начинается именно с этой функции.
- `printf("Hello, World!\n");` выводит текст в консоль.
- `return 0;` означает, что программа завершилась успешно.

## Синтаксис

- Текстовые значения записываются в двойных кавычках.
- Инструкции внутри функции заканчиваются точкой с запятой.
- Фигурные скобки `{}` задают тело функции.

## Компиляция и запуск

Теперь скомпилируем программу. Исходный файл, например, называется `hello.c`.

```bash
gcc hello.c
```

После компиляции обычно появляется исполняемый файл `a.out`. Запустим его:

```bash
./a.out
```

Ожидаемый результат:

```text
Hello, World!
```

## Итоги

- В C программу сначала пишут в исходном файле.
- Затем код компилируют в исполняемый файл.
- После этого программу запускают из терминала.

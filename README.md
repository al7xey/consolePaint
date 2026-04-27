# Console Paint

## Описание

Console Paint - это минимальный консольный C++ проект, демонстрирующий работу с ASCII-холстом и модульную структуру проекта.

## Структура проекта

- `src/` - исходные `.cpp` файлы;
- `include/` - заголовочные `.h` файлы;
- `CMakeLists.txt` - настройка сборки;
- `README.md` - инструкция по сборке и запуску.

## Сборка

```bash
cmake -S . -B build
cmake --build build
```

## Запуск

```bash
cd build
./target_exec
```

Для Windows:

```bash
target_exec.exe
```

## Сторонние библиотеки

Сторонние библиотеки не используются.

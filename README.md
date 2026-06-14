# Console Paint

Console Paint - консольное приложение на C++17 для рисования простых ASCII-картинок.

## Запуск через Docker

Сначала открой Docker Desktop и дождись, пока он полностью запустится. Если Docker Desktop не запущен, команды `docker build` и `docker run` выдадут ошибку подключения к `dockerDesktopLinuxEngine`.

Windows PowerShell:

```powershell
cd D:\consolePaint-1
docker build -t console-paint .
docker run --rm -it console-paint
```

Запуск сразу с командами:

```powershell
docker run --rm console-paint --command "CANVAS 8 4" --command "POINT 2 1 #" --command "SHOW" --command "EXIT"
```

## Запуск без Docker

Windows PowerShell:

```powershell
cd D:\consolePaint-1
cmake -S . -B build
cmake --build build --config Debug --parallel
.\build\Debug\console_paint.exe
```

Запуск сразу с командами:

```powershell
.\build\Debug\console_paint.exe --command "CANVAS 8 4" --command "POINT 2 1 #" --command "SHOW" --command "EXIT"
```

## Тесты

Windows PowerShell:

```powershell
ctest --test-dir build -C Debug --output-on-failure
```

## Linux/macOS

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
./build/console_paint
```

Тесты:

```bash
ctest --test-dir build --output-on-failure
```

Docker:

```bash
docker build -t console-paint .
docker run --rm -it console-paint
```

## Команды приложения

```text
CANVAS 40 20
BRUSH #
POINT 5 5
POINT 6 5 *
LINE 1 1 20 1 *
RECT 2 2 10 5 +
FILL 3 3 @
SHOW
SAVE art.txt
LOAD art.txt
CLEAR
HELP
EXIT
```

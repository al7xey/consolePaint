# Console Paint

Console Paint - консольное приложение на C++17 для создания и редактирования
ASCII-рисунков с помощью текстовых команд.

## Сборка

### Windows PowerShell

```powershell
cmake -S . -B build
cmake --build build --config Debug
```

### Linux/macOS

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Запуск

### Windows PowerShell

Интерактивный режим:

```powershell
.\build\Debug\console_paint.exe
```

Запуск с командами из аргументов:

```powershell
.\build\Debug\console_paint.exe --command "CANVAS 8 4" --command "POINT 2 1 #" --command "SHOW" --command "EXIT"
.\build\Debug\console_paint.exe --script commands.txt
.\build\Debug\console_paint.exe CANVAS 8 4
```

### Linux/macOS

Интерактивный режим:

```bash
./build/console_paint
```

Запуск с командами из аргументов:

```bash
./build/console_paint --command "CANVAS 8 4" --command "POINT 2 1 #" --command "SHOW" --command "EXIT"
./build/console_paint --script commands.txt
./build/console_paint CANVAS 8 4
```

## Команды рисования

```text
CANVAS 40 20 - создание холста размером 40 на 20 символов
BRUSH # - выбор символа кисти по умолчанию
POINT 5 5 - рисование точки текущей кистью в координатах 5 5
POINT 6 5 * - рисование точки символом * в координатах 6 5
LINE 1 1 20 1 * - рисование линии символом * от точки 1 1 до точки 20 1
RECT 2 2 10 5 + - рисование прямоугольника символом + от точки 2 2 до точки 10 5
FILL 3 3 @ - заливка области от точки 3 3 символом @
SHOW - вывод текущего холста в консоль
SAVE art.txt - сохранение рисунка в файл art.txt
LOAD art.txt - загрузка рисунка из файла art.txt
CLEAR - очистка холста
HELP - вывод справки по командам
EXIT - выход из приложения
```

## Тесты

### Windows PowerShell

```powershell
cmake -S . -B build
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

## Docker

Сборка образа:

```bash
docker build -t console-paint .
```

Интерактивный запуск:

```bash
docker run --rm -it console-paint
```

Запуск с командами из аргументов:

```bash
docker run --rm console-paint --command "CANVAS 8 4" --command "POINT 2 1 #" --command "SHOW" --command "EXIT"
```

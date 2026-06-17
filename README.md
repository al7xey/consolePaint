# Console Paint

Console Paint - консольное приложение на C++17 для рисования простых ASCII-картинок.

## Запуск через Docker

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

Имена команд можно писать в любом регистре. Координаты считаются от `0`: `x` идет слева направо, `y` - сверху вниз. Если в командах рисования не указать символ, будет использована текущая кисть.

```text
CANVAS A B              - создает новый пустой холст шириной A и высотой B
BRUSH C                 - меняет текущую кисть на символ C
POINT X Y [C]           - рисует точку в координатах X Y; если C не указан, используется текущая кисть
LINE X1 Y1 X2 Y2 [C]    - рисует линию от точки X1 Y1 до точки X2 Y2
RECT X1 Y1 X2 Y2 [C]    - рисует прямоугольник по двум противоположным углам X1 Y1 и X2 Y2
FILL X Y [C]            - заливает область, в которую попадает точка X Y
SHOW                    - показывает текущий холст в консоли
SAVE FILE               - сохраняет текущий холст в файл FILE
LOAD FILE               - загружает холст из файла FILE
CLEAR                   - очищает холст, не меняя его размер
HELP                    - показывает краткую справку по доступным командам
EXIT                    - завершает работу приложения
```

Пример:

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
```

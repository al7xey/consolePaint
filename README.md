# Console Paint

Console Paint is a small C++17 console application for creating and editing
ASCII drawings with text commands.

## Features

- Create a canvas with a custom size.
- Choose a brush symbol.
- Draw points, lines and rectangles.
- Fill closed areas.
- Clear the canvas.
- Save drawings to text files.
- Load drawings from text files.
- Handle incomplete and unknown commands with readable messages.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
cd build
./console_paint
```

On Windows:

```bash
console_paint.exe
```

## Commands

```text
CANVAS 40 20
BRUSH #
POINT 5 5
POINT 6 5 *
LINE 1 1 20 1 *
RECT 2 2 10 5 +
FILL 3 3 @
SAVE art.txt
LOAD art.txt
CLEAR
HELP
EXIT
```

The drawing commands use the current brush when the symbol argument is omitted.

## Tests

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Third-party libraries

The application itself uses only the C++17 standard library. Tests use
GoogleTest, which is downloaded by CMake through `FetchContent`.

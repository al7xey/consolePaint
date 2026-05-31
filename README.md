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

The application also accepts commands from command-line arguments, which is
useful for Docker and scripts:

```bash
./console_paint --command "CANVAS 8 4" --command "POINT 2 1 #" --command "SHOW" --command "EXIT"
./console_paint --script commands.txt
./console_paint CANVAS 8 4
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
SHOW
SAVE art.txt
LOAD art.txt
CLEAR
HELP
EXIT
```

## Tests

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Unit tests use Catch2 and scenario tests are registered with CTest.

## Docker

Build the multi-stage image:

```bash
docker build -t console-paint .
```

The build stage installs all Linux dependencies, compiles the project, and runs
the full CTest suite. The runtime stage contains only the installed executable.

Run the application in batch mode:

```bash
docker run --rm console-paint --command "CANVAS 8 4" --command "POINT 2 1 #" --command "SHOW" --command "EXIT"
```

Run interactively:

```bash
docker run --rm -it console-paint
```

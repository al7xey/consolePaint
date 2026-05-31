cmake_minimum_required(VERSION 3.10)

project(ConsolePaint VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APP_SOURCES
    src/Canvas.cpp
    src/ConsoleUI.cpp
    src/PaintApplication.cpp
    src/PaintContext.cpp
    src/CommandParser.cpp
    src/CommandFactory.cpp
    src/FileManager.cpp
    src/commands/CanvasCommand.cpp
    src/commands/BrushCommand.cpp
    src/commands/DrawPointCommand.cpp
    src/commands/DrawLineCommand.cpp
    src/commands/DrawRectangleCommand.cpp
    src/commands/FillCommand.cpp
    src/commands/ClearCommand.cpp
    src/commands/ShowCommand.cpp
    src/commands/SaveCommand.cpp
    src/commands/LoadCommand.cpp
    src/commands/ExitCommand.cpp
    src/commands/HelpCommand.cpp
    src/commands/InvalidCommand.cpp
    src/drawing/ShapeDrawer.cpp
    src/drawing/BresenhamLineStrategy.cpp
    src/drawing/QueueFillStrategy.cpp
)

add_library(console_paint_lib ${APP_SOURCES})

target_include_directories(console_paint_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(console_paint_lib PUBLIC /EHsc)
endif()

add_executable(console_paint
    src/main.cpp
)

target_link_libraries(console_paint PRIVATE console_paint_lib)

install(TARGETS console_paint RUNTIME DESTINATION bin)

enable_testing()
add_subdirectory(tests)

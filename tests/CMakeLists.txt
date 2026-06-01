find_package(Catch2 3 QUIET)

if(NOT Catch2_FOUND)
    if(CMAKE_VERSION VERSION_LESS 3.14)
        message(FATAL_ERROR "Catch2 is not installed. Install Catch2 or use CMake 3.14+ so it can be downloaded automatically.")
    endif()

    include(FetchContent)

    FetchContent_Declare(
        Catch2
        URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.5.4.zip
        URL_HASH SHA256=190a236fe0772ac4f5eebfdebfc18f92eeecfd270c55a1e5095ae4f10be2343f
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )

    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif()

add_executable(unit_tests
    unit/CanvasTests.cpp
    unit/CommandParserTests.cpp
    unit/CommandFactoryTests.cpp
    unit/ShapeDrawerTests.cpp
    unit/FillStrategyTests.cpp
    unit/FileManagerTests.cpp
    unit/CommandExecutionTests.cpp
)

target_link_libraries(unit_tests PRIVATE console_paint_lib Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(unit_tests)

add_executable(scenario_draw_basic scenarios/ScenarioDrawBasic.cpp)
target_link_libraries(scenario_draw_basic PRIVATE console_paint_lib)
add_test(NAME ScenarioDrawBasic COMMAND scenario_draw_basic)

add_executable(scenario_fill_closed_area scenarios/ScenarioFillClosedArea.cpp)
target_link_libraries(scenario_fill_closed_area PRIVATE console_paint_lib)
add_test(NAME ScenarioFillClosedArea COMMAND scenario_fill_closed_area)

add_executable(scenario_save_load scenarios/ScenarioSaveLoad.cpp)
target_link_libraries(scenario_save_load PRIVATE console_paint_lib)
add_test(NAME ScenarioSaveLoad COMMAND scenario_save_load)

add_executable(scenario_invalid_input scenarios/ScenarioInvalidInput.cpp)
target_link_libraries(scenario_invalid_input PRIVATE console_paint_lib)
add_test(NAME ScenarioInvalidInput COMMAND scenario_invalid_input)

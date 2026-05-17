include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests
    unit/CanvasTests.cpp
    unit/CommandParserTests.cpp
    unit/CommandFactoryTests.cpp
    unit/ShapeDrawerTests.cpp
    unit/FillStrategyTests.cpp
    unit/FileManagerTests.cpp
    unit/CommandExecutionTests.cpp
)

target_link_libraries(unit_tests PRIVATE console_paint_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)

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

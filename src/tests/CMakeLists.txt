set(XVFB_CMD xvfb-run -a -s "-screen 0 540x960x24")

find_package(Qt5Test REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)
add_definitions(-DCMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

function(add_test_by_name name)
  set(TEST_NAME ${name})
  set(COVERAGE_TEST_TARGETS ${COVERAGE_TEST_TARGETS} ${TEST_NAME} PARENT_SCOPE)
  add_executable (${TEST_NAME} ${TEST_NAME}.cpp)
  add_test(
    NAME ${TEST_NAME}
    COMMAND ${XVFB_CMD} "${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}"
  )
  target_link_libraries(${TEST_NAME}
    ${PLUGIN_NAME}
    Qt5::Test
    ${CMAKE_THREAD_LIBS_INIT}
  )
endfunction()

add_test_by_name(test-clipboard)
add_test_by_name(test-units)
add_test_by_name(test-unitythemeiconprovider)

set(COVERAGE_TEST_TARGETS
  ${COVERAGE_TEST_TARGETS}
  PARENT_SCOPE
)

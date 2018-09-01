find_package(Qt5Test REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

function(add_test_by_name name)
  set(TEST_NAME ${name})
  set(COVERAGE_TEST_TARGETS ${COVERAGE_TEST_TARGETS} ${TEST_NAME} PARENT_SCOPE)
  add_executable (${TEST_NAME} ${TEST_NAME}.cpp)
  add_test(${TEST_NAME} ${TEST_NAME})
  target_link_libraries(${TEST_NAME}
    ${PLUGIN_NAME}
    Qt5::Test
    ${CMAKE_THREAD_LIBS_INIT}
  )
endfunction()

add_test_by_name(test-units)

set(COVERAGE_TEST_TARGETS
  ${COVERAGE_TEST_TARGETS}
  PARENT_SCOPE
)

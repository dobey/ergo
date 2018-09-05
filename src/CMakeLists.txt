
find_package(Qt5Gui REQUIRED)
find_package(Qt5Qml REQUIRED)

configure_file(qmldir.in Ergo/qmldir)
add_library(${PLUGIN_NAME} SHARED
  plugin.cpp

  clipboard.cpp
  clipboard.h
  gettext.cpp
  gettext.h
  units.cpp
  units.h
)

set_target_properties(${PLUGIN_NAME} PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY Ergo
)

target_link_libraries(${PLUGIN_NAME}
  Qt5::Core
  Qt5::Gui
  Qt5::Qml

  ${CMAKE_THREAD_LIBS_INIT}
)

# We need tests
add_subdirectory(tests)

set(COVERAGE_TEST_TARGETS
  ${COVERAGE_TEST_TARGETS}
  PARENT_SCOPE
)

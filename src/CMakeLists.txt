
find_package(Qt5Gui REQUIRED)
find_package(Qt5Qml REQUIRED)

add_library(ergoplugin SHARED
  plugin.cpp

  units.cpp
  units.h
)

set_target_properties(ergoplugin PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY Ergo
)

target_link_libraries(ergoplugin
  Qt5::Core
  Qt5::Gui
  Qt5::Qml

  ${CMAKE_THREAD_LIBS_INIT}
)

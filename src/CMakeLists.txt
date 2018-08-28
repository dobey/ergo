
find_package(Qt5Qml REQUIRED)

add_library(ergoplugin MODULE
  plugin.cpp
)

target_link_libraries(ergoplugin
  Qt5::Core
  Qt5::Qml

  ${CMAKE_THREAD_LIBS_INIT}
)

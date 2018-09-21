find_package(DoxygenBuilder)

add_doxygen(ergo-doc
    INPUT ${CMAKE_SOURCE_DIR}/src
    STRIP_FROM_PATH ${CMAKE_SOURCE_DIR}
    FILE_PATTERNS *.qml *.cpp *.h
    EXCLUDE_PATTERNS */tests/* plugin.cpp unity*
    XML
    ALL
)

project(ergo LANGUAGES C CXX)
cmake_minimum_required(VERSION 3.2.1)

enable_testing()

set(GETTEXT_PACKAGE ${CMAKE_PROJECT_NAME})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)

include(GNUInstallDirs)
if(EXISTS "/etc/debian_version")
    execute_process(
      COMMAND dpkg-architecture -qDEB_HOST_MULTIARCH
      OUTPUT_VARIABLE ARCH_TRIPLET
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )
  set(CMAKE_INSTALL_LIBDIR lib/${ARCH_TRIPLET})
  set(CMAKE_INSTALL_LIBEXECDIR "${CMAKE_INSTALL_LIBDIR}")
  set(CMAKE_INSTALL_FULL_LIBEXECDIR "${CMAKE_INSTALL_FULL_LIBDIR}")
  if(CLICK_MODE)
    set(CMAKE_INSTALL_PREFIX /)
    set(CMAKE_INSTALL_BINDIR lib/${ARCH_TRIPLET}/bin)
  endif(CLICK_MODE)
endif(EXISTS "/etc/debian_version")

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)

#add_subdirectory(po)
add_subdirectory(src)

#find_package(CoverageReport)
#enable_coverage_report(
#  TARGETS 
#  TESTS ${COVERAGE_TEST_TARGETS}
#  FILTER /usr/include ${CMAKE_BINARY_DIR}/*
#)

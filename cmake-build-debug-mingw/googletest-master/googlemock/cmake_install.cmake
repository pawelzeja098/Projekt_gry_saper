# Install script for directory: C:/Users/Piotrek/Desktop/Materiały/obiektowka/cpp/mdig-agh-lang_cpp__exercises-288bd81c85d7/solutions/Projekt_gry_saper/googletest-master/googlemock

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/saper")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/mingw32/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/Users/Piotrek/Desktop/Materiały/obiektowka/cpp/mdig-agh-lang_cpp__exercises-288bd81c85d7/solutions/Projekt_gry_saper/googletest-master/googlemock/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Piotrek/Desktop/Materiały/obiektowka/cpp/mdig-agh-lang_cpp__exercises-288bd81c85d7/solutions/Projekt_gry_saper/cmake-build-debug-mingw/lib/libgmock.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Piotrek/Desktop/Materiały/obiektowka/cpp/mdig-agh-lang_cpp__exercises-288bd81c85d7/solutions/Projekt_gry_saper/cmake-build-debug-mingw/lib/libgmock_main.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Piotrek/Desktop/Materiały/obiektowka/cpp/mdig-agh-lang_cpp__exercises-288bd81c85d7/solutions/Projekt_gry_saper/cmake-build-debug-mingw/googletest-master/googletest/generated/gmock.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Piotrek/Desktop/Materiały/obiektowka/cpp/mdig-agh-lang_cpp__exercises-288bd81c85d7/solutions/Projekt_gry_saper/cmake-build-debug-mingw/googletest-master/googletest/generated/gmock_main.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Piotrek/Desktop/Materiały/obiektowka/cpp/mdig-agh-lang_cpp__exercises-288bd81c85d7/solutions/Projekt_gry_saper/cmake-build-debug-mingw/googletest-master/googletest/cmake_install.cmake")

endif()

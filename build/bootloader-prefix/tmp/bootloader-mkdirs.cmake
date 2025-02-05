# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/eulus/esp/esp-idf/components/bootloader/subproject"
  "/home/eulus/HD/Workspace/ESP32-projects/build/bootloader"
  "/home/eulus/HD/Workspace/ESP32-projects/build/bootloader-prefix"
  "/home/eulus/HD/Workspace/ESP32-projects/build/bootloader-prefix/tmp"
  "/home/eulus/HD/Workspace/ESP32-projects/build/bootloader-prefix/src/bootloader-stamp"
  "/home/eulus/HD/Workspace/ESP32-projects/build/bootloader-prefix/src"
  "/home/eulus/HD/Workspace/ESP32-projects/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/eulus/HD/Workspace/ESP32-projects/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/eulus/HD/Workspace/ESP32-projects/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()

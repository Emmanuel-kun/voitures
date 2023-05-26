# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Voitures_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Voitures_autogen.dir\\ParseCache.txt"
  "Voitures_autogen"
  )
endif()

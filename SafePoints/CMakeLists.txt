cmake_minimum_required(VERSION 2.8)

add_llvm_loadable_module(SAFEPOINTS
	SafePoints.cpp
	BackEdgeSafePoint.cpp
	FuncEntrySafePoint.cpp
)

if(APPLE)
  set_target_properties(SAFEPOINTS PROPERTIES
    COMPILE_FLAGS "-fno-rtti -fvisibility-inlines-hidden -std=c++11 -stdlib=libc++")
else()
  set_target_properties(SAFEPOINTS PROPERTIES
    COMPILE_FLAGS "-fno-rtti -fvisibility-inlines-hidden -std=c++11")
endif(APPLE)

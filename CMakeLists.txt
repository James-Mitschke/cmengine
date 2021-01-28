cmake_minimum_required(VERSION 2.6)
project(CMENGINE)
add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
  src
)

if(MSVC)
  include_directories(
	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_64/include
	)
	link_directories(
	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_64/lib
  )
endif()

add_library(rend
  src/rend/Exception.cpp
  src/rend/Exception.h
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)

if(MSVC OR MINGW)
  target_link_libraries(rend glew32 opengl32 SDL2 openal32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_library(cmengine
  src/cmengine/Core.cpp
  src/cmengine/Core.h

  src/cmengine/Entity.cpp
  src/cmengine/Entity.h

  src/cmengine/Exception.cpp
  src/cmengine/Exception.h

  src/cmengine/Component.cpp
  src/cmengine/Component.h

  src/cmengine/Renderer.cpp
  src/cmengine/Renderer.h

  src/cmengine/Sound.cpp
  src/cmengine/Sound.h

  src/cmengine/Transform.cpp
  src/cmengine/Transform.h

  src/cmengine/Soundsource.cpp
  src/cmengine/Soundsource.h

  src/cmengine/Resource.cpp
  src/cmengine/Resource.h
  src/cmengine/Resources.h

  src/cmengine/cmengine.h
)

target_link_libraries(cmengine rend SDL2)

add_executable(demo
  src/demo/main.cpp
)
target_link_libraries(demo cmengine)
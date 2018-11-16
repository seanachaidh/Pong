cmake_minimum_required(VERSION 3.0.0)
project(pong VERSION 0.1.0)

find_package(PkgConfig)

pkg_check_modules(ALLEGRO REQUIRED allegro-5 allegro_main-5 allegro_font-5 allegro_ttf-5)

include(CTest)
enable_testing()

add_executable(pong main.c menu.c afbeeldingen/arrow.png)
target_link_libraries(pong ${ALLEGRO_LDFLAGS})
target_compile_options(pong PRIVATE ${ALLEGRO_CFLAGS})


set(RESOURCE_FILES afbeeldingen/arrow.png)
set_target_properties(pong PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_FRAMEWORK_IDENTIFIER org.seanachaidh.pong
    RESOURCE "${RESOURCE_FILES}"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

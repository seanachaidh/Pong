cmake_minimum_required(VERSION 3.0.0)
project(pong VERSION 0.1.0)

find_package(PkgConfig)

pkg_check_modules(ALLEGRO REQUIRED allegro-5 allegro_main-5 allegro_font-5 allegro_ttf-5)

include(CTest)
enable_testing()

set(CMAKE_BUILD_TYPE Debug)

set(SOURCE_FILES main.c
                 game.c
                 menu.c
                 ball.c
                 mainheader.h
                 menu.h
                 game.h
                 ball.h)

add_executable(pong ${SOURCE_FILES} afbeeldingen/arrow.png afbeeldingen/funky.otf afbeeldingen/bradly.ttf)
target_link_libraries(pong ${ALLEGRO_LDFLAGS})
target_compile_options(pong PRIVATE ${ALLEGRO_CFLAGS})


set(RESOURCE_FILES afbeeldingen/arrow.png
                   afbeeldingen/funky.otf
                   afbeeldingen/bradly.ttf)
set_target_properties(pong PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_FRAMEWORK_IDENTIFIER org.seanachaidh.pong
    RESOURCE "${RESOURCE_FILES}"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

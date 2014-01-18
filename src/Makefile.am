lib_LTLIBRARIES = lib${PROJECT_SHORT_NAME}.la

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = lib${PROJECT_SHORT_NAME}.pc

include_HEADERS = \
    ../include/${PROJECT_SHORT_NAME}.h \
    ../include/myp_mystatefulmod.h \
    ../include/myp_mystatelessmod.h

lib${PROJECT_SHORT_NAME}_la_SOURCES = \
    myp_mystatefulmod.c \
    myp_mystatelessmod.c

INCLUDES = -I$(top_srcdir)/include
bin_PROGRAMS = ${PROJECT_SHORT_NAME} ${PROJECT_SHORT_NAME}_selftest
${PROJECT_SHORT_NAME}_selftest_LDADD = lib${PROJECT_SHORT_NAME}.la
${PROJECT_SHORT_NAME}_LDADD = lib${PROJECT_SHORT_NAME}.la

if ON_MINGW
lib${PROJECT_SHORT_NAME}_la_LDFLAGS = -no-undefined -avoid-version -version-info @LTVER@
else
lib${PROJECT_SHORT_NAME}_la_LDFLAGS = -version-info @LTVER@
endif

TESTS = ${PROJECT_SHORT_NAME}_selftest


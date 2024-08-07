AM_CPPFLAGS = -Wall
AM_CFLAGS	=
AM_CXXFLAGS =
AM_LDFLAGS	=

AM_CPPFLAGS += -I@top_srcdir@/include
AM_LDFLAGS  += @top_builddir@/src/libgnssxx.la

AM_CPPFLAGS += ${GTEST_MAIN_CFLAGS}
AM_LDFLAGS  += ${GTEST_MAIN_LIBS}

check_PROGRAMS =

check_PROGRAMS += test_arch
test_arch_SOURCES = test_arch.cc

check_PROGRAMS += test_moveable
test_moveable_CXXFLAGS = -std=gnu++98
test_moveable_SOURCES = test_moveable.cc

TESTS = $(check_PROGRAMS)

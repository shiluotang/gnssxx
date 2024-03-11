AM_CPPFLAGS = -Wall
AM_CFLAGS	=
AM_CXXFLAGS =
AM_LDFLAGS	=

AM_CPPFLAGS += -I@top_srcdir@/include
AM_LDFLAGS += @top_builddir@/src/libgnssxx.la

AM_CPPFLAGS += ${GTEST_MAIN_CFLAGS}
AM_LDFLAGS += ${GTEST_MAIN_LIBS}

check_PROGRAMS =

check_PROGRAMS += test_timezone
test_timezone_SOURCES = test_timezone.cc

check_PROGRAMS += test_read_rinex
test_read_rinex_SOURCES = test_read_rinex.cc

TESTS = $(check_PROGRAMS)

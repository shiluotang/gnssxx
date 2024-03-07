AM_CPPFLAGS = -Wall
AM_CFLAGS	=
AM_CXXFLAGS =
AM_LDFLAGS	=

AM_CPPFLAGS += -I@top_srcdir@/include
AM_LDFLAGS += @top_builddir@/src/libgnssxx.la

check_PROGRAMS =

check_PROGRAMS += test1
test1_SOURCES = ./test1.cpp

TESTS = $(check_PROGRAMS)

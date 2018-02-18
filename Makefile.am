ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -Wall
AM_CFLAGS	=
AM_CXXFLAGS =
AM_LDFLAGS	=

lib_LTLIBRARIES = libgnss++.la
libgnss___la_SOURCES = \
					   ./src/gnss.cpp \
					   ./src/time/unixtime.cpp

check_PROGRAMS	= test1
test1_SOURCES	= ./tests/test1.cpp
test1_LDADD		= libgnss++.la

SUBDIRS = src

TESTS = $(check_PROGRAMS)

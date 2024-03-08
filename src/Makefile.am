AM_CPPFLAGS = -Wall
AM_CFLAGS	=
AM_CXXFLAGS =
AM_LDFLAGS	=

AM_CPPFLAGS += -I@top_srcdir@/include

noinst_LTLIBRARIES = libgnssxx.la

libgnssxx_la_SOURCES = \
gnssxx.cpp \
misc/decimal.cpp \
rinex/ion.cc \
rinex/rinex_file_header.cc \
rinex/rinex_file_version.cc \
rinex/rinex_parser.cc \
rinex/rinex_parser_factory.cc \
time/jd.cpp \
time/timezone.cpp \
time/unixtime.cpp

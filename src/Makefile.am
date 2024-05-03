AM_CPPFLAGS = -Wall
AM_CFLAGS	=
AM_CXXFLAGS =
AM_LDFLAGS	=

AM_CPPFLAGS += -I@top_srcdir@/include

noinst_LTLIBRARIES = libgnssxx.la

libgnssxx_la_SOURCES = \
gnssxx.cc \
misc/decimal.cc \
misc/bytes.cc \
rinex/ion.cc \
rinex/rinex_file_header.cc \
rinex/rinex_file_satsys.cc \
rinex/rinex_file_type.cc \
rinex/rinex_file_version.cc \
rinex/rinex_header_parser.cc \
rinex/rinex_header_parser_factory.cc \
rinex/rinex_parser.cc \
rinex/rinex_parser_factory.cc \
time/jd.cc \
time/timezone.cc \
time/unixtime.cc

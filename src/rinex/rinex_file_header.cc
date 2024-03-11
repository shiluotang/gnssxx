#include <memory>
#include <string>

#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_file_header.hh"

namespace gnssxx {
namespace rinex {

rinex_file_version const& rinex_file_header::get_version() const {
    return _M_version;
}

rinex_file_type rinex_file_header::get_type() const {
    return _M_type;
}

rinex_file_satsys rinex_file_header::get_satsys() const {
    return _M_satsys;
}

std::string rinex_file_header::get_pgm() const {
    return _M_pgm;
}

std::string rinex_file_header::get_run_by() const {
    return _M_run_by;
}

std::string rinex_file_header::get_date() const {
    return _M_date;
}

bool rinex_file_header::has_ion() const {
    return !!_M_ion;
}

ion const& rinex_file_header::get_ion() const {
    return *_M_ion;
}

bool rinex_file_header::has_leap_seconds() const {
    return !!_M_leap_seconds;
}

int rinex_file_header::get_leap_seconds() const {
    return *_M_leap_seconds;
}

void rinex_file_header::set_version(rinex_file_version const &value) {
    _M_version = value;
}

void rinex_file_header::set_type(rinex_file_type const &value) {
    _M_type = value;
}

void rinex_file_header::set_satsys(rinex_file_satsys const &value) {
    _M_satsys = value;
}

void rinex_file_header::set_pgm(std::string const &value) {
    _M_pgm = value;
}

void rinex_file_header::set_run_by(std::string const &value) {
    _M_run_by = value;
}

void rinex_file_header::set_date(std::string const &value) {
    _M_date = value;
}

void rinex_file_header::set_ion(ion const &value) {
    _M_ion = std::shared_ptr<ion>(new ion(value));
}

void rinex_file_header::set_leap_seconds(int const &value) {
    _M_leap_seconds = std::shared_ptr<int>(new int(value));
}

} // namespace rinex
} // namespace gnssxx

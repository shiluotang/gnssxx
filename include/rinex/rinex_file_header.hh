#ifndef GNSSXX_RINEX_RINEX_FILE_HEADER_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_FILE_HEADER_HH_INCLUDED

#include <string>
#include <memory>

#include "rinex/rinex_file_version.hh"
#include "rinex/ion.hh"

namespace gnssxx {
namespace rinex {

class rinex_file_header {
    public:
        rinex_file_version const& version() const;

        std::string get_pgm() const;

        std::string get_run_by() const;

        std::string get_date() const;

        bool has_ion() const;

        ion const& get_ion() const;

        bool has_leap_seconds() const;

        int get_leap_seconds() const;
    protected:
    private:
        rinex_file_version _M_version;
        std::string _M_pgm;
        std::string _M_run_by;
        std::string _M_date;
        std::shared_ptr<ion> _M_ion;
        std::shared_ptr<int> _M_leap_seconds;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_FILE_HEADER_HH_INCLUDED

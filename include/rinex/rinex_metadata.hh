#ifndef GNSSXX_RINEX_RINEX_META_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_META_HH_INCLUDED

#include <cstddef>
#include <string>

#include "rinex/rinex_file_version.hh"
#include "rinex/rinex_file_type.hh"
#include "rinex/rinex_file_satsys.hh"

namespace gnssxx {
namespace rinex {

class rinex_metadata {
    public:
        rinex_file_version get_version() const;
        rinex_file_type get_type() const;
        rinex_file_satsys get_satsys() const;

        void set_version(rinex_file_version const&);
        void set_type(rinex_file_type const&);
        void set_satsys(rinex_file_satsys const&);
    protected:
    private:
        rinex_file_version  _M_version;
        rinex_file_type     _M_type;
        rinex_file_satsys   _M_satsys;
};

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_META_HH_INCLUDED

#ifndef GNSSXX_RINEX_RINEX_FILE_VERSION_HH_INCLUDED
#define GNSSXX_RINEX_RINEX_FILE_VERSION_HH_INCLUDED

#include <iomanip>
#include <ostream>

namespace gnssxx {
namespace rinex {

class rinex_file_version {
    public:
        rinex_file_version(int major, int minor);
        rinex_file_version();

        int get_major() const;
        int get_minor() const;

        void set_major(int);
        void set_minor(int);

        void print(std::ostream& out) const;

        bool operator<(rinex_file_version const &other) const;
        bool operator==(rinex_file_version const &other) const;
    protected:
    private:
        int _M_major;
        int _M_minor;
};

std::ostream& operator<<(std::ostream &os, rinex_file_version const &v);

} // namespace rinex
} // namespace gnssxx

#endif // GNSSXX_RINEX_RINEX_FILE_VERSION_HH_INCLUDED

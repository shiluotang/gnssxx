#ifndef GNSSXX_TIME_JD_HH_INCLUDED
#define GNSSXX_TIME_JD_HH_INCLUDED

#include <cstddef>

namespace gnssxx {
namespace time {

class jd {
    public:
        explicit jd(double);
        virtual ~jd();
    private:
        double _M_jd;
};

} // namespace time
} // namespace gnssxx

#endif // GNSSXX_TIME_JD_HH_INCLUDED

#ifndef GNSSXX_TIME_JD_HPP_INCLUDED
#define GNSSXX_TIME_JD_HPP_INCLUDED

#include <cstddef>

namespace gnssxx {

    class jd {
        public:
            explicit jd(double);
            virtual ~jd();
        private:
            double _M_jd;
    };
}

#endif // GNSSXX_TIME_JD_HPP_INCLUDED

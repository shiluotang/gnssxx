#ifndef GNSSXX_TIME_UNIXTIME_HPP_INCLUDED
#define GNSSXX_TIME_UNIXTIME_HPP_INCLUDED

#include <ctime>
#include <ostream>

namespace gnssxx {

    /**
     * The seconds since unix epoch 1970-01-01 00:00:00 GMT.
     *
     * @author shengquangang2015@163.com
     * @version Sun Sep 17 00:31:18 CST 2017
     */
    class unixtime {
        public:
            explicit unixtime(std::time_t);
            explicit unixtime(double);
            unixtime(std::time_t, double);

            virtual ~unixtime();

            operator time_t() const { return static_cast<std::time_t>(_M_seconds); }
            operator double() const { return _M_seconds; }

            std::time_t integral() const { return static_cast<std::time_t>(_M_seconds); }
            double fraction() const { return _M_seconds - static_cast<std::time_t>(_M_seconds); }
            double to_jd() const;

            unixtime& operator = (unixtime const&);

            static unixtime now();
            static unixtime from_jd(double);
        private:
            double _M_seconds;
    };
}

#endif // GNSSXX_TIME_UNIXTIME_HPP_INCLUDED

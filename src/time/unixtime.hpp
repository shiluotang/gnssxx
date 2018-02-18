#ifndef GNSSXX_TIME_UNIXTIME_HPP_INCLUDED
#define GNSSXX_TIME_UNIXTIME_HPP_INCLUDED

#include <ctime>

namespace gnss {

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

            operator time_t() const { return _M_time; }
            time_t integral() const { return _M_time; }
            double fraction() const { return _M_fraction; }
            double toJD() const;

            unixtime& operator = (unixtime const&);

            static unixtime now();
            static unixtime fromJD(double);
        private:
            std::time_t _M_time;
            double _M_fraction;
    };
}

#endif // GNSSXX_TIME_UNIXTIME_HPP_INCLUDED

#ifndef GNSSXX_TIME_TIMEZONE_HPP_INCLUDED
#define GNSSXX_TIME_TIMEZONE_HPP_INCLUDED

namespace gnssxx {
    namespace time {
        class timezone {
        private:
            static int offset0();
        public:
            static int offset();
        };

    }
}

#endif // GNSSXX_TIME_TIMEZONE_HPP_INCLUDED

#ifndef GNSSXX_TIME_TIMEZONE_HH_INCLUDED
#define GNSSXX_TIME_TIMEZONE_HH_INCLUDED

namespace gnssxx {
namespace time {

class timezone {
private:
    static int offset0();
public:
    static int offset();
};

} // namespace time
} // namespace gnssxx

#endif // GNSSXX_TIME_TIMEZONE_HH_INCLUDED

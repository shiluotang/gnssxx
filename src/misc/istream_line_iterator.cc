#include <string>
#include <istream>

#include "misc/istream_line_iterator.hh"

namespace gnssxx {
namespace misc {

istream_line_iterator::istream_line_iterator(std::istream *in)
    :_M_in(in)
    ,_M_line()
{
    this->operator++();
}

istream_line_iterator::istream_line_iterator(
        istream_line_iterator const &other)
    : _M_in(other._M_in)
    , _M_line(other._M_line)
{
}

istream_line_iterator&
istream_line_iterator::operator++() {
    if (!_M_in)
        return *this;
    if (!std::getline(*_M_in, _M_line)) {
        if (_M_line.empty())
            _M_in = nullptr;
    }
    return *this;
}

istream_line_iterator
istream_line_iterator::operator++(int) {
    istream_line_iterator copy(*this);
    this->operator++();
    return copy;
}

bool
istream_line_iterator::operator==(istream_line_iterator const &other) const {
    return _M_in == other._M_in;
}

bool
istream_line_iterator::operator!=(istream_line_iterator const &other) const {
    return _M_in != other._M_in;
}

istream_line_iterator::value_type
istream_line_iterator::operator*() const {
    return _M_line;
}

} // namespace misc
} // namespace gnssxx

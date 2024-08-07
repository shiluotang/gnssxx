#include <iomanip>
#include <ostream>
#include <algorithm>
#include <string>

#include "misc/utils.hh"
#include "misc/bytes.hh"

namespace gnssxx {
namespace misc {

bytes::bytes(bytes const &other)
    : _M_data(other._M_data) {
}

bytes::~bytes() {
    _M_data = value_type();
}

bytes::bytes(void const *addr, size_t n)
    :_M_data()
{
    this->assign(addr, n);
}

bytes::bytes(char const *s)
    : _M_data()
{
    this->assign(s, std::char_traits<char>::length(s));
}

bytes::bytes()
    : _M_data()
{
}

void bytes::print(std::ostream& out) const {
    uint8_t const *p = static_cast<uint8_t const*>(&_M_data[0]);
    gnssxx::misc::ios_guarder guarder(out);
    for (int i = 0, n = _M_data.size(); i < n; ++i) {
        out
            << std::setw(2)
            << std::setfill('0')
            << std::hex
            << std::uppercase
            << (p[i] & 0xff);
    }
}

bytes& bytes::operator=(bytes const &other) {
    return this->assign(other);
}

bytes& bytes::operator=(char const *s) {
    return this->assign(s, std::char_traits<char>::length(s));
}

bytes& bytes::operator+=(bytes const &other) {
    return this->append(other);
}

bytes bytes::operator+(bytes const &other) const {
    bytes copy(*this);
    copy.append(other);
    return copy;
}

bool bytes::operator<(bytes const &other) const {
    return this->compare(other) < 0;
}

bool bytes::operator==(bytes const &other) const {
    return this->compare(other) == 0;
}

bytes::ubyte& bytes::operator[](size_t i) {
    return _M_data[i];
}

bytes::ubyte const& bytes::operator[](size_t i) const {
    return _M_data[i];
}

void bytes::swap(bytes &other) {
    _M_data.swap(other._M_data);
}

size_t bytes::size() const {
    return _M_data.size();
}

void const* bytes::addr() const {
    if (_M_data.size() > 0)
        return &_M_data[0];
    return static_cast<void const*>(0);
}

void* bytes::addr() {
    if (_M_data.size() > 0)
        return &_M_data[0];
    return static_cast<void*>(0);
}

bytes& bytes::assign(bytes const &other) {
    _M_data = other._M_data;
    return *this;
}

bytes& bytes::assign(void const *addr, size_t n) {
    value_type c(
            static_cast<uint8_t const*>(addr),
            static_cast<uint8_t const*>(addr) + n);
    c.swap(_M_data);
    return *this;
}

bytes& bytes::append(bytes const &other) {
    int osize = _M_data.size();
    int nsize = osize + other._M_data.size();
    _M_data.resize(nsize);
    std::copy_n(
            &other._M_data[0],
            other._M_data.size(),
            &_M_data[osize]);
    return *this;
}

int bytes::compare(bytes const &other) const {
    int c = std::char_traits<ubyte>::compare(
            static_cast<ubyte const*>(addr()),
            static_cast<ubyte const*>(other.addr()),
            std::min(size(), other.size()));
    if (c != 0)
        return c;
    c = size() - other.size();
    return c;
}

std::ostream& operator<<(std::ostream &out, bytes const &b) {
    b.print(out);
    return out;
}

} // namespace misc
} // namespace gnssxx

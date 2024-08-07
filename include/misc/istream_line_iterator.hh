#ifndef GNSSXX_MISC_ISTREAM_LINE_ITERATOR_HH_INCLUDED
#define GNSSXX_MISC_ISTREAM_LINE_ITERATOR_HH_INCLUDED

#include <cstddef>
#include <iosfwd>
#include <iterator>

namespace gnssxx {
namespace misc {

class istream_line_iterator
#if __cplusplus < 201703L
    : public std::iterator<std::input_iterator_tag, std::string>
#endif
{
    public:
#if __cplusplus >= 201703L
        typedef std::input_iterator_tag iterator_category;
        typedef std::string value_type;
        typedef ptrdiff_t   difference_type;
        typedef std::string *pointer;
        typedef std::string &reference;
#endif

        explicit istream_line_iterator(std::istream* = NULL);
        istream_line_iterator(istream_line_iterator const&);

        istream_line_iterator& operator++();
        istream_line_iterator operator++(int);
        bool operator==(istream_line_iterator const &other) const;
        bool operator!=(istream_line_iterator const &other) const;
        value_type operator*() const;
    protected:
    private:
        std::istream *_M_in;
        std::string _M_line;
};

} // namespace misc
} // namespace gnssxx

#endif // GNSSXX_MISC_ISTREAM_LINE_ITERATOR_HH_INCLUDED

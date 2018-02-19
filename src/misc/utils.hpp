#ifndef GNSS_MISC_UTILS_HPP_INCLUDED
#define GNSS_MISC_UTILS_HPP_INCLUDED

#include <iomanip>
#include <ios>
#include <string>
#include <locale>

namespace gnssxx {
    namespace misc {
        template <typename CharT, typename CharTraits = std::char_traits<CharT> >
        struct basic_ios_guarder {
            typedef std::streamsize streamsize;
            typedef std::locale     locale;
            typedef typename std::basic_ios<CharT> xios;
            typedef typename xios::fmtflags     fmtflags;
            typedef typename xios::char_type    char_type;

            explicit basic_ios_guarder(xios &stream)
                : _M_stream(stream)
                , _M_flags(stream.flags())
                , _M_fillchar(stream.fill())
                , _M_width(stream.width())
                , _M_precision(stream.precision())
                , _M_locale(stream.getloc())
            {
            }

            virtual ~basic_ios_guarder() {
                _M_stream.flags(_M_flags);
                _M_stream.fill(_M_fillchar);
                _M_stream.width(_M_width);
                _M_stream.precision(_M_precision);
                _M_stream.imbue(_M_locale);
            }

            xios        &_M_stream;
            fmtflags    _M_flags;
            char_type   _M_fillchar;

            streamsize _M_width;
            streamsize _M_precision;
            locale     _M_locale;
        };

        typedef basic_ios_guarder<char> ios_guarder;
        typedef basic_ios_guarder<wchar_t> wios_guarder;
    }
}

#endif // GNSS_MISC_UTILS_HPP_INCLUDED

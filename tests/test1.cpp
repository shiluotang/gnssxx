#include <cstdlib>

#include "../src/gnss.hpp"

namespace gnss {
    template <typename CharT,
             typename Traits = std::char_traits<CharT>,
             typename Alloc = std::allocator<CharT> >
    class basic_simplebuf : public std::basic_streambuf<CharT> {
        public:
            typedef typename Traits::int_type int_type;
        public:
            virtual int_type underflow() {
                return 0;
            }

            virtual int_type overflow(int_type ch = Traits::eof()) {
                return 0;
            }

            virtual int_type sync() {
                return 0;
            }
    };

    typedef basic_simplebuf<char> simplebuf;
    typedef basic_simplebuf<wchar_t> wsimplebuf;
}

int main(int argc, char* argv[]) {
    using namespace std;
    using namespace gnss;

    // ostream oss(new ::gnss::simplebuf);
    return EXIT_SUCCESS;
}

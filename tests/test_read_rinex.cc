#include <cstdlib>
#include <ctime>

#include <map>
#include <iomanip>
#include <sstream>
#include <ostream>
#include <iostream>

#include "gnssxx.hpp"
#include "rinex/rinex_parser_factory.hh"

int main(int argc, char* argv[]) {
    using gnssxx::rinex::rinex_parser_factory;
    using gnssxx::rinex::rinex_parser;

    rinex_parser_factory::instance()->set_parser(2, 0, nullptr);
    std::shared_ptr<rinex_parser> ptr = rinex_parser_factory::instance()->for_version(2, 0);
    std::cout << ptr << std::endl;
    return EXIT_SUCCESS;
}

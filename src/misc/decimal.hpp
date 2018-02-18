#ifndef GNSSXX_MISC_DECIMAL_HPP_INCLUDED
#define GNSSXX_MISC_DECIMAL_HPP_INCLUDED

#include <iosfwd>
#include <vector>

namespace gnss {
    namespace misc {

        /**
         * Aritrary precision float point number.
         *
         * @author shengquangang2015@163.com
         */
        class decimal {
            public:
                // -------------------------------------
                // implicit conversion from primitives
                // @{
                // -------------------------------------
                decimal(char);
                decimal(short);
                decimal(int);
                decimal(long int);
                decimal(long long int);

                decimal(unsigned char);
                decimal(unsigned short);
                decimal(unsigned int);
                decimal(unsigned long int);
                decimal(unsigned long long int);

                decimal(float);
                decimal(double);
                decimal(long double);
                // -------------------------------------
                // @}
                // -------------------------------------

                decimal(decimal const&);
                virtual ~decimal();

                decimal& operator = (decimal const&);

                // -------------------------------------
                // arithmetic operators overload
                // @{
                // -------------------------------------
                decimal& operator += (decimal const&);
                decimal& operator -= (decimal const&);
                decimal& operator *= (decimal const&);
                decimal& operator /= (decimal const&);
                decimal& operator %= (decimal const&);

                decimal operator + (decimal const&) const;
                decimal operator - (decimal const&) const;
                decimal operator * (decimal const&) const;
                decimal operator / (decimal const&) const;
                decimal operator % (decimal const&) const;
                // -------------------------------------
                // @}
                // -------------------------------------

                // -------------------------------------
                // comparison operators overload
                // @{
                // -------------------------------------
                bool operator <  (decimal const&) const;
                bool operator >  (decimal const&) const;
                bool operator == (decimal const&) const;
                bool operator != (decimal const&) const;
                bool operator <= (decimal const&) const;
                bool operator >= (decimal const&) const;
                // -------------------------------------
                // @}
                // -------------------------------------

                // -------------------------------------
                // conversion to primitives
                // @{
                // -------------------------------------
                operator short() const;
                operator int() const;
                operator long int() const;

                operator unsigned short() const;
                operator unsigned int() const;
                operator unsigned long int() const;

                operator float() const;
                operator double() const;
                operator long double() const;
                // -------------------------------------
                // @}
                // -------------------------------------
            private:
                std::vector<unsigned char> _M_binary;
            private:
                // friendship
                friend std::ostream& operator << (std::ostream&, decimal const&);
                friend std::istream& operator >> (std::istream&, decimal&);
        };

        extern std::ostream& operator << (std::ostream&, decimal const&);
        extern std::istream& operator >> (std::istream&, decimal&);
    }
}

#endif // GNSSXX_MISC_DECIMAL_HPP_INCLUDED

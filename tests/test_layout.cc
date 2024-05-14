#include <gtest/gtest.h>

#include "misc/utils.hpp"
#include "misc/cxl.h"

class base1 {
    public:
        virtual ~base1() { }

        int _M_f11;
        int _M_f12;
        int _M_f13;
    protected:
    private:
};

class base2 {
    public:
        virtual ~base2() { }
        int _M_f21;
    protected:
    private:
};

class derived : public base1, public base2 {
    public:
        virtual ~derived() {}
    protected:
    private:
};

#define DUMP(x) \
    do { \
        std::cout << #x " = " << x << std::endl; \
    } while (false);

TEST(layout_test, test_address) {
    using gnssxx::misc::pointer_cast;
    DUMP(sizeof(base1));
    DUMP(offsetof(base1, _M_f11));
    DUMP(offsetof(base1, _M_f12));
    DUMP(offsetof(base1, _M_f13));
    DUMP(sizeof(base2));
    DUMP(sizeof(derived));
    DUMP(offsetof(derived, _M_f11));
    DUMP(offsetof(derived, _M_f12));
    DUMP(offsetof(derived, _M_f13));
    DUMP(offsetof(derived, _M_f21));
    derived *ptr_derived = new derived();
    base1 *ptr_base1 = ptr_derived;
    base2 *ptr_base2 = ptr_derived;
    DUMP(pointer_cast<void*>(ptr_derived));
    DUMP(pointer_cast<void*>(ptr_base1));
    DUMP(pointer_cast<void*>(ptr_base2));
    DUMP(pointer_cast<void*>(dynamic_cast<derived*>(ptr_base1)));
    DUMP(pointer_cast<void*>(dynamic_cast<derived*>(ptr_base2)));
}

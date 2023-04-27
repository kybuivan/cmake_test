#include <iostream>
#include <rttr/registration>
#include <rttr/type>

using namespace rttr;
struct test_class
{
    test_class(int value) : m_value(value) {}
    void print_value() const { std::cout << m_value << std::endl; }
    int m_value;
    RTTR_ENABLE()
};

RTTR_REGISTRATION
{
    registration::class_<test_class>("test_class")
        .constructor<int>()
        .method("print_value", &test_class::print_value)
        .property("value", &test_class::m_value);
}

int main()
{
    // option 1
    type class_type = type::get_by_name("test_class");
    if (class_type)
    {
        variant obj = class_type.create({23});
        
        method meth = class_type.get_method("print_value");
        meth.invoke(obj);
        destructor dtor = class_type.get_destructor();
        dtor.invoke(obj);
    }
    // option 2
    if (class_type)
    {
        constructor ctor = class_type.get_constructor({type::get<int>()});
        variant obj = ctor.invoke(23);
        method meth = class_type.get_method("print_value");
        meth.invoke(obj);
        destructor dtor = class_type.get_destructor();
        dtor.invoke(obj);
    }
    return 0;
}
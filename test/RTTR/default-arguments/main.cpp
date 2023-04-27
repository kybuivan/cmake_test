#include <iostream>
#include <rttr/registration>

void my_function(int a, bool b, const std::string& text, const int* ptr)
{
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "text = " << text << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
}

RTTR_REGISTRATION
{
    using namespace rttr;
    registration::method("my_function", &my_function)   
    (
        default_arguments(true, std::string("default text"), nullptr)
    );
}

int main()
{
    using namespace rttr;
    method meth = type::get_global_method("my_function");
    // the default values: 'true', 'std::string("default text"'), 'nullptr' will be forwarded by RTTR automatically
    variant var = meth.invoke(instance(), 23);
    std::cout << var.is_valid(); // prints 'true'
    // the default value: 'nullptr' will be forwarded by RTTR automatically
    var = meth.invoke(instance(), 23, true, std::string("text"));
    std::cout << var.is_valid(); // prints 'true'

    return 0;
}
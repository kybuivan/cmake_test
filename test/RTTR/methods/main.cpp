#include <iostream>
#include <rttr/registration>

#include <cmath>
RTTR_REGISTRATION
{
    using namespace rttr;
    registration::method("pow", static_cast<double(*)(double, double)>(&std::pow));
}

using namespace rttr;
int main()
{
    // let asume we have registered the pow function: double pow( double base, double exp );
    // option 1
    variant return_value = type::invoke("pow", {9.0, 2.0});
    if (return_value.is_valid() && return_value.is_type<double>())
        std::cout << return_value.get_value<double>() << std::endl; // 81
    // option 2
    method meth = type::get_global_method("pow");
    if (meth) // check if the function was found
    {
        return_value = meth.invoke({}, 9.0, 3.0); // invoke with empty instance
        if (return_value.is_valid() && return_value.is_type<double>())
            std::cout << return_value.get_value<double>() << std::endl; // 729
    }

    return 0;
}
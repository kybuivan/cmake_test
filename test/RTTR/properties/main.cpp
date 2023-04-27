#include <iostream>
#include <rttr/registration>

static const double pi = 3.14259;
static std::string global_text;
void set_text(const std::string& text) { global_text = text; }
const std::string& get_text() { return global_text; }
RTTR_REGISTRATION
{
    using namespace rttr;
    registration::property_readonly("PI", &pi);
    registration::property("global_text", &get_text, &set_text);
}

using namespace rttr;
int main()
{
    // option 1, via type
    variant value = type::get_property_value("PI"); // remark the capitalization of "PI"
    if (value && value.is_type<double>())
        std::cout << value.get_value<double>() << std::endl; // outputs: "3.14259"
    // option 2, via property class
    property prop = type::get_global_property("PI");
    if (prop)
    {
        value = prop.get_value(instance());
        if (value.is_valid() && value.is_type<double>())
            std::cout << value.get_value<double>() << std::endl; // outputs: "3.14259"
    }

    return 0;
}
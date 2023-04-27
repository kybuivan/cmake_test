#include <iostream>
#include <rttr/registration>
#include <rttr/type>

bool g_Value = false;

using namespace rttr;
enum class MetaData_Type
{
    SCRIPTABLE,
    GUI
};

RTTR_REGISTRATION
{
    registration::property("value", &g_Value)
        (    
            metadata(MetaData_Type::SCRIPTABLE, false), 
            metadata("Description", "This is a value.")
        );
}

int main()
{
    property prop = type::get_global_property("value");
    variant value = prop.get_metadata(MetaData_Type::SCRIPTABLE);
    std::cout << value.get_value<bool>() << std::endl; // prints "false"
    
    value = prop.get_metadata("Description");
    std::cout << value.get_value<std::string>() << std::endl; // prints "This is a value."

    return 0;
}
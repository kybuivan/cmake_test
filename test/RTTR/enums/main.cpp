#include <iostream>
#include <rttr/registration>
using namespace rttr;
enum class E_Alignment
{
    AlignLeft       = 0x0001,
    AlignRight      = 0x0002,
    AlignHCenter    = 0x0004,
    AlignJustify    = 0x0008
};

RTTR_REGISTRATION
{
    registration::enumeration<E_Alignment>("E_Alignment")
        (
            value("AlignLeft",    E_Alignment::AlignLeft),
            value("AlignRight",   E_Alignment::AlignRight),
            value("AlignHCenter", E_Alignment::AlignHCenter),
            value("AlignJustify", E_Alignment::AlignJustify)
        );
}

int main()
{
    type enum_type = type::get_by_name("E_Alignment");
    if (enum_type && enum_type.is_enumeration())
    {
        enumeration enum_align = enum_type.get_enumeration();
        rttr::string_view my_string_view = enum_align.value_to_name(E_Alignment::AlignHCenter); // stores "AlignHCenter"
        std::string name = my_string_view.to_string();
        variant var = enum_align.name_to_value(name);
        E_Alignment value = var.get_value<E_Alignment>(); // stores value 'AlignHCenter'
        std::cout << var.to_string() << std::endl;
    }
    return 0;
}
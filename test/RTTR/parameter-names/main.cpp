#include <iostream>
#include <rttr/registration>

void set_window_geometry(const char* name, int w, int h)
{
    std::cout << "set_window_geometry: " << name << " " << w << " " << h << std::endl;
}

RTTR_REGISTRATION
{
    using namespace rttr;
    registration::method("set_window_geometry", &set_window_geometry)
    (
        parameter_names("window name", "width", "height")
    );
}

int main()
{
    using namespace rttr;
    method meth = type::get_global_method("set_window_geometry");
    auto param_range = meth.get_parameter_infos();
    std::vector<parameter_info> param_list(param_range.begin(), param_range.end());
    for (const auto& info : param_list)
    {
        // print all names of the parameter types and its position in the paramter list
        std::cout << " name: '" << info.get_type().get_name() << "'\n"
                  << "index: " << info.get_index()
                  << std::endl;
    }

    // output:
    //  name: 'const char*'
    // index: 0
    //  name: 'int'
    // index: 1
    //  name: 'int'
    // index: 2

    return 0;
}
#include <iostream>
#include <rttr/registration>

using namespace rttr;
int main()
{
    variant var;
    var = 23;                               // copy integer
    int x = var.to_int();                   // x = 23
    var = "Hello World";                    // var contains now a std::string (implicit conversion of string literals to std::string)
    int y = var.to_int();                   // y = 0, because invalid conversion
    var = "42";                             // contains a std::string
    std::cout << var.to_int() << std::endl;              // convert std::string to integer and prints "42"
    int my_array[100];
    var = my_array;                         // copies the content of my_array into var
    auto& arr = var.get_value<int[100]>();  // extracts the content of var by reference
    arr[0] = 23;                            // modifies the content of my_array
    std::cout << my_array[0] << std::endl;               // prints 23
    return 0;
}
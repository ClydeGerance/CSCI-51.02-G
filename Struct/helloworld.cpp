#include <iostream>

struct student{
    std::string name;
    double gpa;
    bool enrolled;
};

int main()
{
    student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.2;
    student1.enrolled = true;

    student student2;
    student2.name = "Patrick";
    student2.gpa = 2.1;
    student2.enrolled = true;

    student student3 = {"Squidward", 4.0, true};

    std::cout << student1.name << '\n';
    std::cout << student1.gpa << '\n';
    std::cout << student1.enrolled << '\n';

    std::cout << student2.name << '\n';
    std::cout << student2.gpa << '\n';
    std::cout << student2.enrolled << '\n';

    std::cout << student3.name << '\n';
    std::cout << student3.gpa << '\n';
    std::cout << std::boolalpha << student3.enrolled << '\n';

    return 0;
}

/*
Observations:
1. Structs allow grouping related variables of different types into a single unit.
2. Accessing and modifying struct members is done using the dot (.) operator.
3. Initialization can be done either manually (assigning values one by one) or using a list.
4. std::boolalpha makes boolean values print as "true" or "false" instead of 1 or 0.
5. Structs in C++ are similar to classes but have public members by default.

Comparison with Java and Python:
- C++ structs are similar to Java classes but lack built-in encapsulation features like private/public methods.
- In Python, dictionaries or objects (from classes) can achieve similar grouping but are more dynamic.
- C++ struct members have fixed types, unlike Python, which allows dynamic typing.
- C++ is more memory efficient compared to Python due to its static typing.
- Java requires explicit class definitions with getters and setters, whereas C++ structs allow direct access.
*/

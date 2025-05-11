// week2
void constant()
{
    // the const keeyword specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it.
    // (read-only)
    const double pi = 3.14159;
    // pi = 3.14;  some one change
    const double radius = 10;
    const double result = 2 * pi * radius;

    cout << result << "cm" << endl;
}

namespace first{
    int x = 5;
}
namespace second{
    int y = 10;
}

void namespaceFunction()
{
    // namespace = provide a solution for preventing name conflicts
    // in a large project . each entity need a unique name
    using namespace first;
 int x = 0;
 int y = 0;
cout << x << endl;
cout << first << endl;
cout << second::y << endl;

}

void cmathFunction()
{
    int x = -10;
    int y = 20;
    int z;
    //  z = max(x,y);
    // z = min(x,y);
    // z = sqrt(y);
    // z = round(x);
    // z = ceil(x);
    // z = floor(x);
    // z = abs(x);
    // z = pow(x);

    cout << "Val = " << z << endl;
}

void userinput()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "what is your name";
    string name;
    cin >> name;

    cout << "your name is: " << name << " and your age is: " << age << endl;
}
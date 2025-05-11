// week3
void typedefFunction()
{
    /*
    typedef = allows you to create an alias for a data type 
     reverse keyword uesed to create additional names (alias) for another data type
     Help with readability and  reduce types 
    repace with (using) better 
   */

    // typedef std::string text_t;
    typedef int number_t;
    using Isok = bool;
    using  text_t = std::string ;

    Isok isOK = true;
    text_t name = "neth";
    number_t age = 23;
    cout << name << endl;
    cout << age << endl;
    cout << isOK << endl;
}

void basicArithmetic()
{
    // arithmetic operator = return the result of a specific arithmetic operation (+ - * /)
    
     int student = 20;
     student = student + 20;
     student += 20;
     
    // z = x + y;
    // z = x - y;
    // z = x * y;
    // z = x / y;
    // z = x % y;
    // z = x++;
    // z = x--;
    // z = x += y;
    // z = x -= y;
    // z = x -= y;
    // z = x *= y;
    // z = x /= y;
    // z = x *= y;
    // z = x /= y;
    // z = x %= y;
    cout << "Val = " << student << endl;
}
void typeOfConversion(){
    // type conversion = conversion a value of one data type to another
    //  implicit  = automatic 
    //  Explicit = Precede  value with new data type int 

    // double x = 34.4;
    double x = (int) 34.4;
    char text = 100;
    cout << text <<endl;
    cout << x <<'\n';
}

void squarRoot()
{
    int a;
    int b;
    int c;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));
    cout << "The value of c is: " << c << endl;
}

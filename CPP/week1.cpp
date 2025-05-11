

// week1  install and setup
void hellow(){
    // this is a comment
    /*
    this 
    is 
    a multi 
    line comments
    */
    cout << "Hello World" << endl;
    cout << "I am learning C++" << '\n';
}

//  variables and basic data types 
void variables(){
    int x; // declaration 
    x = 5; // assignment   x = 5; // assignment 
    cout << x << endl;
}


void dataType(){
      // integer (whole numbers)
    int age = 23;
    int year =2025;
    int days = 7;

    // double (numebers including decimal points)
    double price = 10.99;
    double gpa = 2.5;
    double temperture = 98.6;

    // char (single character)
    char letter = 'A';
    char symbol = '$';
    char curency = '@';

    // string (a object that represent a  sequence of text)
    string name = "John";
    string movie = "Finding Nemo";

    // boolean (true or false)
    bool isOK = true;
    bool isCorrect = false;
    bool student = true;

    cout << "Age: " << age << endl;
    cout << "Price: " << price << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Temperture: " << temperture << endl;
    cout << "Letter: " << letter << endl;
    cout << "Symbol: " << symbol << endl;
    cout << "Curency: " << curency << endl;
}
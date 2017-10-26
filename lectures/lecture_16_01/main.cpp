#include <iostream>

using namespace std;

class Timi {
public:
    Timi();  // Default constructor
    Timi(int k, int m);  // Additional constructor
    Timi(int m);  // Third constructor, useful for automatic type conversion

    // set functions for klst and minutur.  These functions then call the private fix
    // functions to make sure that the Timi object always contains proper time values.
    void set_klst(int k);
    void set_minutur(int m);

    // get functions for klst and minutur.  Set the function as const to show that we're
    // not making any changes here.
    int get_klst() const;
    int get_minutur() const;

    // get the time as minutes, this is a short const function so it is implemented inside the class
    int to_minutes() const {
        return 60*klst + minutur;
    };

    // Overloading some of the arithmetic functions, this allows us to use normal math,
    // such as + and - when we're dealing with objects of type Timi
    // The parameters are called lhs and rhs, which stands for left-hand-side and right-hand-side
    // to indicate where the parameters are in relation to the operator.
    friend Timi operator + (const Timi &lhs, const Timi &rhs);
    friend Timi operator + (const Timi &lhs, int tala);
    friend Timi operator - (const Timi &lhs, const Timi &rhs);

    // Overloading multiplication and division
    // We don't know what multiplicating or dividing two times should mean, we can however
    // easily multiply or divide time with a number
    friend Timi operator * (const Timi &lhs, int tala);
    friend Timi operator * (int tala, const Timi &lhs);
    friend Timi operator / (const Timi &lhs, int tala);

    // Unary operator, taking only one parameter
    friend Timi operator - (const Timi &lhs);

    // Overloading the comparisons, used when comparing two objects of type Timi
    friend bool operator < (const Timi &lhs, const Timi &rhs);
    friend bool operator == (const Timi &lhs, const Timi &rhs);
    friend bool operator <= (const Timi &lhs, const Timi &rhs);
    friend bool operator > (const Timi &lhs, const Timi &rhs);
    friend bool operator >= (const Timi &lhs, const Timi &rhs);
    friend bool operator != (const Timi &lhs, const Timi &rhs);

    // Overloading the input and the output.  This is the standard way of defining these functions
    // Timi (the second parameter) is const for << since that is only printing out the values, we
    // cannot use const for >> since there we're actually changing the values.
    friend ostream& operator << (ostream& outs, const Timi &t);
    friend istream& operator >> (istream& ins, Timi &t);

    // Overloading the increment and decrement operators, both prefix (++t) and postfix (t++) version.
    // The postfix version (i.e. t++) has an unnamed int parameter so the compiler knows which
    // version we're implementing.  The syntax is a bit different from other operators.
    Timi operator++();
    Timi operator++(int);
    Timi operator--();
    Timi operator--(int);

private:
    // The variables are private, so the user must go through get/set functions
    int klst;
    int minutur;

    // Private functions that make sure that the information in Timi is always of the correct form.
    // These are private since they are only to be used within the class, not by the user
    void fix_klst();
    void fix_minutur();
};

// Constructors, both the default constructor and another constructor with parameters.
// These constructors contain cout to let us know when they are used.  These should be removed before actually using this class.
Timi::Timi() {
    klst = 0;
    minutur = 0;

    //cout << "Constructor: Timi()" << endl;
}

Timi::Timi(int k, int m) {
    klst = k;
    minutur = m;

    fix_minutur();
    fix_klst();

    //cout << "Constructor: Timi(int k, int m)" << endl;
}

Timi::Timi(int m) {
    klst = 0;
    minutur = m;

    fix_minutur();
    fix_klst();

    //cout << "Constructor: Timi(int m)" << endl;
}

// Set functions, these change the values of the hours and the minutes.  We then call the fix functions to
// make sure that the object contains proper time values.
void Timi::set_klst(int k) {
    klst = k;
    fix_klst();
}

void Timi::set_minutur(int m) {
    minutur = m;
    fix_minutur();
    fix_klst();
}

// Get functions.  These are very simple, just returning the values of the variables.  Since we don't make
// any changes, we mark these functions as const.
int Timi::get_klst() const {
    return klst;
}

int Timi::get_minutur() const {
    return minutur;
}



// Here we add two objects of type Timi.  We just add the hours and minutes, then we use the fix functions
// to make sure that the new object is valid.
Timi operator + (const Timi &lhs, const Timi &rhs) {
    Timi tnew;
    tnew.klst = lhs.klst + rhs.klst;
    tnew.minutur = lhs.minutur + rhs.minutur;
    tnew.fix_minutur();
    tnew.fix_klst();
    return tnew;
}

// Adding Timi and tala (increasing the minutes).  This function is not necessary since the automatic type
// conversion works correctly after we supplied the correct constructor (with one int parameter).
Timi operator + (const Timi &lhs, int tala) {
    Timi tnew(lhs.klst, lhs.minutur);
    tnew.minutur += tala;

    tnew.fix_minutur();
    tnew.fix_klst();
    return tnew;
}

// Subtracting Timi from Timi
Timi operator - (const Timi &lhs, const Timi &rhs) {
    Timi tnew(lhs.klst - rhs.klst, lhs.minutur - rhs.minutur);
    tnew.fix_minutur();
    tnew.fix_klst();
    return tnew;
}

// Unary operator, negative time...
Timi operator - (const Timi &lhs) {
    Timi tnew;
    tnew.klst = -lhs.klst;
    tnew.minutur = -lhs.minutur;

    tnew.fix_minutur();
    tnew.fix_klst();
    return tnew;
}

// Overload multiplication, we change everything to minutes, multiply them and then change back
// using the fix functions
Timi operator * (const Timi &lhs, int tala) {
    Timi tnew;

    tnew.klst = 0;
    tnew.minutur = tala * (60 * lhs.klst + lhs.minutur);

    tnew.fix_minutur();
    tnew.fix_klst();

    return tnew;
}
// The other order of the parameters, using the previous function.
Timi operator * (int tala, const Timi &lhs) {
    return lhs * tala;
}

// ...and division, same strategy.
Timi operator / (const Timi &lhs, int tala) {
    Timi tnew;

    tnew.klst = 0;
    tnew.minutur = (60 * lhs.klst + lhs.minutur) / tala;

    tnew.fix_minutur();
    tnew.fix_klst();

    return tnew;
}




// Comparing two Times.  We base the comparison on the hours and minutes of the Timi objects
// and return boolean values to indicate which Timi is greater or less than the other
bool operator < (const Timi &lhs, const Timi &rhs) {
    if (lhs.klst < rhs.klst) {
        return true;
    }
    else if (lhs.klst == rhs.klst && lhs.minutur < rhs.minutur) {
        return true;
    }
    else {
        return false;
    }
}

// Figuring out if two Timi are the same is easy:
bool operator == (const Timi &lhs, const Timi &rhs) {
    return (lhs.klst == rhs.klst && lhs.minutur == rhs.minutur);
}

// And then we can use what we've built to generate other comparisons
bool operator <= (const Timi &lhs, const Timi &rhs) {
    return (lhs == rhs || lhs < rhs);
}
bool operator > (const Timi &lhs, const Timi &rhs) {
    return !(lhs <= rhs);
}
bool operator >= (const Timi &lhs, const Timi &rhs) {
    return !(lhs < rhs);
}
bool operator != (const Timi &lhs, const Timi &rhs) {
    return !(lhs == rhs);
}


// Here we write out the information to either screen or to file.  The left hand side parameter
// is of type ostream, which includes for example "cout".  We add our stuff to the ostream parameter
// and then return it.  Then, once the function has completed, the information stored in the ostream
// parameter outs is printed to the output, for example to screen if cout is the first parameter.
ostream& operator << (ostream& outs, const Timi &t) {
    if (t.klst < 10) {
        outs << "0";
    }
    outs << t.klst << ":";
    if (t.minutur < 10) {
        outs << "0";
    }
    outs << t.minutur;

    return outs;
}

// Read in values from some inputstream (for example cin or file).  Here we cannot print anything
// since then the function would not be useful when dealing with files.  We just read in two
// integer numbers to use as klst and minutur, and then fix the values using the private fix functions.
// The return value of this function is just the istream object that is the left hand side parameter, we
// return it after we read from it what we want.
istream& operator >> (istream& ins, Timi &t) {
    ins >> t.klst >> t.minutur;

    t.fix_minutur();
    t.fix_klst();

    return ins;
}


// Private fix functions, these make sure that the hour value is in the range 0-23 and minutes in 0-59.
void Timi::fix_minutur() {
    while (minutur < 0) {
        minutur += 60;
        klst--;
    }
    while (minutur >= 60) {
        minutur -= 60;
        klst++;
    }
}

void Timi::fix_klst() {
    while (klst < 0) {
        klst += 24;
    }
    while (klst >= 24) {
        klst -= 24;
    }
}


//Just for fun, overloading the increment and decrement operator
Timi Timi::operator++() {
    minutur++;
    fix_minutur();
    fix_klst();
    return *this;
}

Timi Timi::operator++(int) {
    Timi t = *this;
    minutur++;
    fix_minutur();
    fix_klst();
    return t;
}

Timi Timi::operator--() {
    minutur--;
    fix_minutur();
    fix_klst();
    return *this;
}

Timi Timi::operator--(int) {
    Timi t = *this;
    minutur--;
    fix_minutur();
    fix_klst();
    return t;
}





// The main function is just testing the various properties of the Timi class.
int main() {
    Timi t1, t2(17,3);  // create two objects of type Timi, using different constructors.

    // Using the set functions.
    t1.set_klst(3);
    t1.set_minutur(8);

    // Print out t1, using the overloaded << operator.
    cout << endl << "Overloaded output function:" << endl;
    cout << t1 << endl;

    t2.set_minutur(185);
    cout << t2 << endl;


    cout << endl << "Adding two Timi objects:" << endl;
    Timi t3;  // create a new object to use for addition
    t3 = t1 + t2;  // adding two objects of type Timi, using the overloaded operator +
    cout << t3 << endl;

    cout << endl << "Comparing two Timi objects:" << endl;
    if (t1 <= t2) {       // comparing two objects of type Timi, using <=
        cout << t1 << endl;
    }
    else {
        cout << t2 << endl;
    }

    // Test the input function
    cout << endl << "Please write klst and minutes: " << endl;
    cin >> t1;

    cout << t1 << endl;

    // Set the minutes of t1 equal to 15;
    t1.set_minutur(15);

    cout << endl << "Value of t1:" << endl;
    cout << t1 << endl;

    cout << endl << "Simple addition:" << endl;
    cout << t1 + t1 << endl;

    cout << endl << "Timi plus int:" << endl;
    cout << t1 + 15 << endl;

    cout << endl << "int plus Timi:" << endl;
    cout << 15 + t1 << endl;

    // finally try multiple things at the same time.  It would give good insights into how things are called if
    // we add cout statements to the functions above to see when they are called when we run statement like this.
    cout << endl << "Adding three Timi objects" << endl;
    cout << t1 + t2 + t3 << endl;

    // Subtracting times...
    cout << endl << "Subtracting Timi objects, version 1" << endl;
    cout << t1 - t2 << endl;
    cout << endl << "Subtracting Timi objects, version 2" << endl;
    cout << -t2 + t1 << endl;

    // Multiplication and division
    cout << endl << "Value of t1: " << t1 << endl;
    cout << endl << "Multiply t1 by 4:" << endl;
    cout << t1 * 4 << endl;

    cout << endl << "Multiply t1 by 2:" << endl;
    cout << 2 * t1 << endl;

    cout << endl << "Divide t1 by 3:" << endl;
    cout << t1 / 3 << endl;


    // Testing the increment and decrement operators:
    cout << endl << "Increment operator, starting with the postfix version" << endl;
    cout << t1 << endl;
    cout << t1++ << endl;
    cout << t1 << endl;
    cout << "then the prefix version" << endl;
    cout << t1 << endl;
    cout << ++t1 << endl;
    cout << t1 << endl;

    cout << endl << "Decrement operator, starting with the postfix version" << endl;
    cout << t1 << endl;
    cout << t1-- << endl;
    cout << t1 << endl;
    cout << "then the prefix version" << endl;
    cout << t1 << endl;
    cout << --t1 << endl;
    cout << t1 << endl;

    if (t1 != t2) {
        cout << "not same";
    }

    return 0;
}



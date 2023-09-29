#include <iostream>

using namespace std;

// Forward declaration of ImproperFraction class
class ImproperFraction;

// Base class Fraction
class Fraction
{
protected:
    int numerator, denominator, whole_number;

public:
    Fraction() {}
    Fraction(int num, int denum) : numerator(num), denominator(denum), whole_number(0) {}

    // Overloaded addition operator
    Fraction operator+(Fraction op2)
    {
        Fraction temp;
        temp.whole_number = 0;
        temp.numerator = (numerator * op2.denominator) + (op2.numerator * denominator);
        temp.denominator = denominator * op2.denominator;

        // Simplify the result fraction
        int common_gcd = gcd(temp.numerator, temp.denominator);
        temp.numerator /= common_gcd;
        temp.denominator /= common_gcd;
        return temp;
    }

    // Overloaded multiplication operator
    Fraction operator*(Fraction op2)
    {
        Fraction temp;
        temp.whole_number = 0;
        temp.numerator = numerator * op2.numerator;
        temp.denominator = denominator * op2.denominator;

        // Simplify the result fraction
        int common_gcd = gcd(temp.numerator, temp.denominator);
        temp.numerator /= common_gcd;
        temp.denominator /= common_gcd;

        return temp;
    }

    // Virtual function to show the fraction
    virtual void showFraction()
    {
        cout << numerator << "/" << denominator;
    }



    // Calculate decimal value of the fraction
    float toDecimal()
    {
        return static_cast<float>(numerator) / denominator;
    }
        // Convert Fraction to ImproperFraction
    operator ImproperFraction() const;

    // Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

// Derived class ImproperFraction
class ImproperFraction : public Fraction
{
private:
    bool mixed;

public:
    ImproperFraction() : mixed(false) {}

    // Constructor with whole, numerator, and denominator
    ImproperFraction(int whole, int num, int denum)
    {
        numerator = num;
        denominator = denum;
        whole_number = whole;
        if (numerator / denominator)
        {
            mixed = true;
        }
    }

    // Convert to mixed fraction
    void toMixedFraction()
    {
        whole_number = numerator / denominator;
        numerator %= denominator;
    }

    // Convert to improper fraction
    void toImproperFraction()
    {
        numerator = (whole_number * denominator) + numerator;
        whole_number = 0;
    }

    // Show the fraction
    void showFraction()
    {
        if (mixed)
        {
            this->toMixedFraction();
        }
        cout << whole_number << ", " << numerator << "/" << denominator;
    }
};

// Conversion operator from Fraction to ImproperFraction
Fraction::operator ImproperFraction() const
{
    return ImproperFraction(0, numerator, denominator);
}

// Derived class ProperFraction
class ProperFraction : public Fraction
{
public:
    ProperFraction() {}
    ProperFraction(int num, int denum) : Fraction(num, denum) {}
};

int main()
{
    // Clear screen (not recommended in production)
     system("cls");

    // Create ProperFraction instances
    ProperFraction Pfrac1(1, 2), Pfrac2(1, 2);

    // Add ProperFractions and convert to ImproperFraction
    ImproperFraction temp = Pfrac1 + Pfrac2;
    temp.showFraction();
    cout << endl;

    // Create and manipulate ImproperFractions
    ImproperFraction Imp(2, 3, 4);
    Imp.toImproperFraction();
    ImproperFraction Imp1(0, 5, 3);
    ImproperFraction temp1 = Imp + Imp1;
    temp1.showFraction();
    cout << endl;

    // Create ProperFraction and ImproperFraction instances
    ProperFraction Pfrac5(1, 2);
    ImproperFraction Pfrac4(0, 5, 3);

    // Multiply and show result
    ImproperFraction temp2 = Pfrac4 * Pfrac5;
    temp2.showFraction();
    cout << endl;

    // Multiply and show result
    ImproperFraction temp3 = Imp * Imp1;
    temp3.showFraction();
    cout << endl;

    // Show decimal values
    cout << Pfrac1.toDecimal() << endl;
    cout << Imp1.toDecimal() << endl;
    cout << Imp.toDecimal() << endl;

    return 0;
}

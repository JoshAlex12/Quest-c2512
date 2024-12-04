#include <iostream>
#include <cstdlib>
using namespace std;
"hi" class Fraction
{
private:
    // Data members
    int numerator;
    int denominator;

public:
    // Utility function to calculate GCD using the Euclidean algorithm
    int calculateGCD(int a, int b) const
    {
        // while (b != 0)
        // {
        //     int temp = b;
        //     b = a % b;
        //     a = temp;
        // }
        // return a;
        while (denominator != 0)
        {
            int temp = denominator;
            denominator = numerator % denominator;
            numerator = temp;
        }
        return numerator;
    }

    // Simplify the fraction
    void simplify()
    {
        int gcd = calculateGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // Ensure the denominator is always positive
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    // Parameterized constructor
    Fraction(int p_numerator, int p_denominator)
    {
        if (p_denominator == 0)
        {
            cout << "Error: Denominator cannot be zero!" << endl;
            exit(1);
        }
        numerator = p_numerator;
        denominator = p_denominator;
        simplify();
    }

    // Default constructor
    Fraction() : numerator(0), denominator(1) {}

    // Add function to add two fractions
    Fraction Add(const Fraction &other) const
    {
        int n_numerator = (numerator * other.denominator) + (other.numerator * denominator);
        int n_denominator = denominator * other.denominator;
        return Fraction(n_numerator, n_denominator); // Create a new simplified fraction
    }

    // Display function to print the fraction
    void display() const
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    // Create two fraction objects
    Fraction f1(1, 2); // Represents 1/2
    Fraction f2(2, 3); // Represents 2/3

    // Add two fractions
    Fraction result = f1.Add(f2);
    cout << "Sum of two fractions: ";
    result.display(); // Expected output: 7/6 (in reduced form)

    // Create a third fraction
    Fraction f3(3, 4); // Represents 3/4

    // Add three fractions
    Fraction result2 = f1.Add(f2.Add(f3));
    cout << "Sum of three fractions: ";
    result2.display(); // Expected output: 23/12 (in reduced form)

    return 0;
}

// class Fraction
// {
// private:
//     int numerator;   // To store the numerator
//     int denominator; // To store the denominator

//     // Utility function to calculate GCD using the Euclidean algorithm
//     int calculateGCD(int a, int b) const
//     {
//         while (b != 0)
//         {
//             int temp = b;
//             b = a % b;
//             a = temp;
//         }
//         return a;
//     }

//     // Utility function to simplify the fraction
//     void simplify()
//     {
//         int gcd = calculateGCD(abs(numerator), abs(denominator));
//         numerator /= gcd;
//         denominator /= gcd;
//         // Ensure the denominator is always positive
//         if (denominator < 0)
//         {
//             numerator = -numerator;
//             denominator = -denominator;
//         }
//     }

// public:
//     // Default constructor: represents 0/1
//     Fraction() : numerator(0), denominator(1) {}

//     // Parameterized constructor
//     Fraction(int num, int den) : numerator(num), denominator(den)
//     {
//         if (denominator == 0)
//         {
//             cout << "Error: Denominator cannot be zero." << endl;
//             exit(EXIT_FAILURE); // Terminate the program
//         }
//         simplify();
//     }

//     // Add function to add two fractions
//     Fraction Add(const Fraction &other) const
//     {
//         int newNumerator = numerator * other.denominator + other.numerator * denominator;
//         int newDenominator = denominator * other.denominator;
//         return Fraction(newNumerator, newDenominator); // Result in simplified form
//     }

//     // Display function to print the fraction
//     void display() const
//     {
//         cout << numerator << "/" << denominator << endl;
//     }
// };

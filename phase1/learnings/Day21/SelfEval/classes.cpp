int gcdCalc(int num, int den)
{
}

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction addFraction(const Fraction &other);
    // Fraction substractFraction(const Fraction& other);

    Fraction();
};

Fraction::addFraction(const Fraction &other)
{
    Fraction third(0, 1);
    third.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator)
                                                                  third.denominator = (this->denominator * other.denominator);
}
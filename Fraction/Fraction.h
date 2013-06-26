//Fraction.h 
class Fraction
{
 public:
  Fraction();
  Fraction(int, int);
  Fraction operator+(Fraction&);
  Fraction operator-(Fraction&);
  Fraction operator*(Fraction&);
  Fraction operator/(Fraction&);
  bool operator==(Fraction&);
  bool operator!=(Fraction&);
  bool operator>(Fraction&);
  bool operator<(Fraction&);
  void display();
  int gcd(int,int);
 private:
  int numerator;
  int denominator;
};

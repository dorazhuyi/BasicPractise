//Fraction.cpp
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "Fraction.h"

using namespace std;

Fraction::Fraction()
{
 numerator = 1;
 denominator = 1;
}

Fraction::Fraction(int n, int d)
{
 // Demominator cannot be zero
 if(d==0)
 {
   cout << "Error: Denominator is zero." << endl;
   exit (EXIT_FAILURE);
 }
 // Always put the negtive sign at numerator
 else
 {
   if(d<0){n = -n; d = -d;}
   numerator = n;
   denominator = d;
 }
}

Fraction Fraction::operator+(Fraction &f)
{
 // a/b + c/d = (ad + bc) / bd
 int n = numerator*f.denominator + denominator*f.numerator;
 int d = denominator*f.denominator;
 return (Fraction(n/gcd(n,d),d/gcd(n,d)));
}

Fraction Fraction::operator-(Fraction &f)
{
 // a/b - c/d = (ad - bc) / bd
 int n = numerator*f.denominator - denominator*f.numerator;
 int d = denominator*f.denominator;
 return (Fraction(n/gcd(n,d),d/gcd(n,d)));
}

Fraction Fraction::operator*(Fraction &f)
{
 // a/b * c/d = ac / bd
 int n = numerator*f.numerator;
 int d = denominator*f.denominator;
 return (Fraction(n/gcd(n,d),d/gcd(n,d)));
}

Fraction Fraction::operator/(Fraction &f)
{
 // Divisor cannot be zero
 if(f.numerator == 0)
 {
   cout << "Error: Divided by zero." << endl;
   exit (EXIT_FAILURE);
 }
 // a/b / c/d = ad / bc 
 int n = numerator*f.denominator;
 int d = denominator*f.numerator;
 // Always put the negtive sign at numerator
 if(d<0){n = -n; d = -d;}
 return (Fraction(n/gcd(n,d),d/gcd(n,d)));
}

bool Fraction::operator==(Fraction &f)
{
 int n = numerator/gcd(numerator,denominator);
 int d = denominator/gcd(numerator,denominator);
 int nf = f.numerator/gcd(f.numerator,f.denominator);
 int df = f.denominator/gcd(f.numerator,f.denominator);
 return (n==nf && d==df);
}

bool Fraction::operator!=(Fraction &f)
{
 int n = numerator/gcd(numerator,denominator);
 int d = denominator/gcd(numerator,denominator);
 int nf = f.numerator/gcd(f.numerator,f.denominator);
 int df = f.denominator/gcd(f.numerator,f.denominator);
 return !(n==nf && d==df);
}

bool Fraction::operator>(Fraction &f)
{
 int n = numerator*f.denominator - denominator*f.numerator;
 return n>0;
}

bool Fraction::operator<(Fraction &f)
{
 int n = numerator*f.denominator - denominator*f.numerator;
 return n<0;
}

void Fraction::display()
{
 cout << numerator << "/" << denominator << endl;
}

int Fraction::gcd(int n, int d)
{
 int tmp;
 // Always returns positive number
 n = abs(n);
 d = abs(d);
 while(d!=0)
 {
  tmp = n%d;
  n = d;
  d = tmp;
 }
 return n;
}


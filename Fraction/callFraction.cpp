//callFraction.cpp
#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
 Fraction f1(12,19);
 Fraction f2(11,16);
 f1.display();
 f2.display();
 
 Fraction sum = f1+f2;
 Fraction diff = f1-f2;
 Fraction product = f1*f2;
 Fraction quo = f1/f2;

 sum.display();
 diff.display();
 product.display();
 quo.display();

 if(f1==f2) cout << "f1 = f2" << endl;
 if(f1!=f2) cout << "f1 != f2" << endl;
 if(f1<f2) cout << "f1 < f2" << endl;
 if(f1>f2) cout << "f1 > f2" << endl;
 
 return 0;
}

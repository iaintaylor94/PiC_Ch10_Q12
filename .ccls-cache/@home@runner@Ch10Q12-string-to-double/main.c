// Program to convert a string to its floating point equivalent - including negative numbers

#include <stdio.h>
#include <stdbool.h>

// Declare Functions
bool isNegative (char);
int positiveStringToInt (char []);
int stringToInt (const char []);
double stringToDouble (char []);

int main(void) {

  char inStr[] = "01234.56789";
  char inStrTwo[] = ".1234";
  char inStrThree[] = "-00123.4567";

  printf ("InputString: %s\n", inStr);
  printf ("OutputString: %lf\n\n", stringToDouble (inStr));

  printf ("InputString: %s\n", inStrTwo);
  printf ("OutputString: %lf\n\n", stringToDouble (inStrTwo));

  printf ("InputString: %s\n", inStrThree);
  printf ("OutputString: %lf\n\n", stringToDouble (inStrThree));
  
  
  return 0;
}

// Define Functions
bool isNegative (char c) {
  if (c == '-')
    return true;
  else
    return false;
}

int positiveStringToInt (char string[]) {
  int i, intValue, result = 0;

  for (i = 0; string[i] >= '0' && string[i] <= '9'; i++) {
    intValue = string[i] - '0';
    result = result * 10 + intValue;
  }

  return result;
}

int stringToInt (const char string[]) {
  int result = 0;
  int minus = isNegative(string[0]);
  char localString [strlen(string)];
  strcpy (localString, string);

  if (minus)
    localString[0] = '0';

  result = positiveStringToInt (localString);

  if (minus)
    result *= -1;

  return result;
}

double stringToDouble (char inputString[]) {
  double output = 0;
  bool negative = false;
  
  if (inputString[0] == '-') {
    negative = true;
    inputString[0] = '0';
  }

  int integerSize = 0, fractionSize = 0;

  int i;
  for (i = 0; inputString[i] != '.'; i++) 
    ;
    integerSize = i;

  fractionSize = strlen(inputString) - integerSize - 1;

  char integer [integerSize];

  for (int i = 0; i < integerSize; i++) 
    integer [i] = 1;
  integer [integerSize] = '\0';

  char fraction [fractionSize];
  
  if (inputString[integerSize + 1] == '.')
    fractionSize++;
  
  for (int i = 0; i < fractionSize; i++) 
    fraction [i] = 1;
  fraction [fractionSize] = '\0';


  for ( i = 0; i < integerSize; i++) {
    integer [i] = inputString [i];
  }

  for (int i = 0; i < fractionSize; i++) {
    fraction [i] = inputString [integerSize + 1 + i];
  }

  if (fraction[0] == '.')
    for (int i = 0; i <= fractionSize; i++)
      fraction[i] = fraction[i + 1];


  double outInteger = stringToInt (integer);

  double outFraction = stringToInt (fraction);
  for (int i = 0; i < fractionSize; i ++)
    outFraction /= 10;


  output += outInteger;
  output += outFraction;

  if (negative)
    output *= - 1;

  
  return output;
}
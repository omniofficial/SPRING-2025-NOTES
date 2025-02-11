/* QUESTION 2: WRITE A PROBLEM DEFINITION AND PSEUDOCODE FOR EACH OF THE FOLLOWING PROBLEMS*/

-------------------------------------------------------------------
(a) Computing a square root

/* A. PROBLEM DEFINITION: Given a list of numbers compute the square root of all elements in a non-root list by iterating over each element and appending it to a root list. Compare the two lists, and return the root list while making sure both values are aligned. */

/* A. PSEUDOCODE: */
Initialize list with numbers
Initialize rootlist as empty list

for x in list:
  Take the square root of x
  rootlist.append(x)

  for (int i = 0; i < list.size(); i++) {
  print "Number: " << list[i] << "Square Root: " << rootlist[i];
  }

  
-------------------------------------------------------------------
(b) Determining whether an integer is even or odd

/* B. PROBLEM DEFINITION: In order to determine whether an integer is even or odd, we will be utlizing logic from the previous question 1 (b), whenre remainder = num % denom. Given an integer num, determine whether the number is even or odd by calculating the remainder when divided by 2. If the remainder is 0, the number is even. Otherwise, it is odd. */

/* B. PSEUDOCODE: */
int remainder = num % 2;

if (remainder == 0){
cout << "Integer is even";
}

else {
cout << "Integer is odd";
}


-------------------------------------------------------------------
(c) Determining whether every element in a sequence is identical

/* C. PROBLEM DEFINITION: Given a provided sequence of numbers stored in an array, determine whether every element in a sequence is identical. Determine whether elements are identical depending on the first element of the sequence. areIdentical is flagged false if any element different from the first element, and it outputs "Elements in provided sequence do not match". Otherwise if they are identical output "All elements are identical". */

/* C. PSEUDOCODE: */
initialize int sequence
int n = sizeof(sequence) / sizeof(sequence[0]);

if (n == 0) {
  cout << "Sequence is empty!";
}

else {
bool areIdentical = true;
int first_element = sequence[0];

for (int i = 1; i < n; ++i) {
  if (sequence[i] != first_element) {
    areIdentical = false;
    return;
  }
}

}

if (areIdentical) {
  cout << "Provided strings are identical";
}
else {
  cout << "Provided strings are not identical";
}


-------------------------------------------------------------------
(d) Determining whether two strings are identical

/* D. PROBLEM DEFINITION: Given two strings, determine whether they are identical by comparing each character within the strings. If the strings have the same length and all characters are equal, then the areIdentical flag will be flagged true, where a message will return: "Provided strings are identical". Otherwise, the flag will return false and a message will return "Provided strings are not identical."*/

/* D. PSEUDOCODE: */
Initialize string1
Initialize string2

if (string1.length() != string2.length()) {
  cout << "Strings are not identical due to string length. One is longer (or shorter) than the other.";
}

else {
  bool areIdentical = true;

  for (size_t = 0; i < string1.length(); ++i) {
    if (string1[i] != string2[i]) {
      areIdentical = false;
      return;
    }
  }
}

if (areIdentical) {
  cout << "Provided strings are identical";
}
else {
  cout << "Provided strings are not identical";
}


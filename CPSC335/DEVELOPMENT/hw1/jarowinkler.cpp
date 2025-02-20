#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*----------- SLIDE 1.1 SNIPPET: FINDING MATCHING CHARACTERS -----------*/
double jaro(const string &s1, const string &s2)
{
  int len1 = s1.length();
  int len2 = s2.length();

  // CALCULATING MATCH DISTANCE
  int matchDistance = max(len1, len2) / 2 - 1;

  // WHERE WE TRACK MATCHES
  int s1Matches[len1] = {0};
  int s2Matches[len1] = {0};
  int matches = 0;        // Total # of matches
  int transpositions = 0; // Total # of transpositions

  // FIND OUR MATCHING CHARACTERS
  for (int i = 0; i < len1; i++) // Outer loop iterated through each char of string1. 
  {
    int start = max(0, i - matchDistance); // Determines start index for inner loop
    int end = min(i + matchDistance + 1, len2); // Determines end index for outer loop

    for (int j = start; j < end; j++) // For every char in string1, inner loop iterates through characters in string2 within match distance, where we determine if char match.
    {
      if (s1[i] == s2[j] && s2Matches[j] == 0) // If string1 char = string2 char, and string2 char has not been matched...
      {
        s1Matches[i] = 1; // Character in string1 is matched
        s2Matches[j] = 1; // Character in string2 is matched
        matches++; // Keep track of match count by incrementing
        break;
      }
    }
  }

/*----------- SLIDE 1.2 SNIPPET: COUNTING TRANSPOSITIONS -----------*/


/*----------- SLIDE 1.3 SNIPPET: CALCULATING THE JARO SIMILARITY SCORE -----------*/

/*----------- SLIDE 2.1 SNIPPET: IDENTIFYING THE COMMON PREFIX -----------*/

/*----------- SLIDE 2.2 SNIPPET: APPLYING THE WINKLER ADJUSTMENT -----------*/

/*----------- SLIDE 3.1 SNIPPET: FINDING THE OVERALL SIMILARITY SCORE -----------*/




}

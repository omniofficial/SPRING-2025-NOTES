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
    int start = max(0, i - matchDistance);      // Determines start index for inner loop
    int end = min(i + matchDistance + 1, len2); // Determines end index for outer loop

    for (int j = start; j < end; j++) // For every char in string1, inner loop iterates through characters in string2 within match distance, where we determine if char match.
    {
      if (s1[i] == s2[j] && s2Matches[j] == 0) // If string1 char = string2 char, and string2 char has not been matched...
      {
        s1Matches[i] = 1; // Character in string1 is matched
        s2Matches[j] = 1; // Character in string2 is matched
        matches++;        // Keep track of match count by incrementing
        break;
      }
    }
  }

  /*----------- SLIDE 1.2 SNIPPET: COUNTING TRANSPOSITIONS -----------*/
  int n = 0;                     // Inner loop iterator that tracks index of matched characters in string2.
  for (int i = 0; i < len1; i++) // Outer loop iterates through string1 length. Takes each char in string1 and compares to each char in string2. Stops once the max length is met.
  {
    if (s1Matches[i] == 1) // As long as string1 character has been matched with a string2 character, then this will trigger.
    {
      while (s2Matches[n] == 0) // This while loop will keep running as long as characters in string2 have not been matched yet. However, once it encounters a string that has been matched, then the loop will exit since the condition becomes false., and our if statement starts.
        n++;
      if (s1[i] != s2[n]) // When comparing string1 to string2, if they do not have the same index (position) , then it is a transposition.
        transpositions++;
      n++;
    }
  }

  /*----------- SLIDE 1.3 SNIPPET: CALCULATING THE JARO SIMILARITY SCORE -----------*/
  double jaroSimilarity = (matches / (double)len1 + matches / (double)len2 + (matches - transpositions / 2.0) / matches) / 3.0; // FIND JARO SIMILARITY
  return jaroSimilarity;
}

/*----------- SLIDE 2.1 SNIPPET: IDENTIFYING THE COMMON PREFIX -----------*/

double jaroWinklerSimilarity(const string &s1, const string &s2, double jaroSimilarity)
{
  // If Jaro similarity is 1.0, no need to adjust (exact match)
  if (jaroSimilarity == 1.0)
    return 1.0;

  // Determine the length of common prefix (up to 4 characters)
  int commonPrefix = 0;
  for (int i = 0; i < (4, min(s1.length(), s2.length())); i++)
  {
    if (s1[i] == s2[i])
    {
      commonPrefix++;
    }
    else
    {
      break;
    }
  }

  /*----------- SLIDE 2.2 SNIPPET: APPLYING THE WINKLER ADJUSTMENT -----------*/
  double P = 0.1;
  double winklerAdjustment = P * commonPrefix * (1 - jaroSimilarity);

  /*----------- SLIDE 3.1 SNIPPET: FINDING THE OVERALL SIMILARITY SCORE -----------*/
  double jaroWinklerSimilarity = jaroSimilarity + winklerAdjustment;
  return jaroWinklerSimilarity;
}

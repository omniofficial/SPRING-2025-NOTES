/* QUESTION 1: Each of the following snippets of pseudocode fails to live up to all of the clarity,
correctness, and termination requirements of algorithms. In each case, describe the problem, and
then rewrite the pseudocode as a proper algorithm */
// DISCLAIMER: FOR REDUNDANCY PURPOSES, FOR ALL PSEUDOCODE WE WILL ASSUME THE FUNCTION IS CALLED VIA main().


-------------------------------------------------------------------
(a) for list:
total = total + i

/* A. PROBLEM: Orignally, this pseudocode represents a summation algorithm that calculates the sum of all elements within a list. However, unfortunately it is not detailed enough as it missed key components such as initializing the total variable or how we are looping through said list. Also, we do not know whether the loop should stop once completing the full list or stopping at the desired value.  */

/* A. REWRITTEN PSEUDOCODE: */
(a) total = 0;
for each value i in list:
total = total + i 
return total


-------------------------------------------------------------------
(b) def long_division(num, denom):
quotient = num // denom
remainder = num % denom

/* B. PROBLEM: This given pseudocode represents a long division algorithm that processed borth large numbers and remainders. However, this does not deal with decimal values and only deals with int values as the quotient is given by a whole number divided by the denomerator. In addition to this value, a remainder is obtained. Unfortunately, there is a problem as we have no direction as to if we would like for the quotient and remainder to be outputted back to the user. The given psuedocode does not specify how to return our data, whether via one string or through pass by reference. Additionally, we have to take into consideration division by 0. For our new pseudocode, we will choose to pass by reference for simplicity.*/

/* B. REWRITTEN PSUEDOCODE: */
void long_division(const int &num, const int &denom, int &quotient, int &remainder) {
if denom = 0, then 
return "There is an error. Operation cannot be performed due to division by 0";

else
quotient = num // denom
remainder = num % denom
}

int main() {
  int num; // DOES NOT CHANGE AFTER USER INPUT
  int denom; // DOES NOT CHAGE AFTER USER INPUT
  int quotient;
  int remainder;

  long_division(num, denom, quotient, remainder);
}


-------------------------------------------------------------------
(c) def keep_positives(S):
if len(S) == 0:
return 0
else:
result = []
for x in S:
if x > 0:
result.add(x)
return result

/* C. PROBLEM: The originall algorithm for the provided psuedocode attempts to return only positive values from a provided list. For any non-positive numbers, they are skipped over and only positive values are added to the result list. The problem with the provided pseudocode is that we should be returning an empty list when our input list S is empty. This makes it clearer to both the user and ourselves that the list is truly empty rather than returning 0. Additionally, we tend to use result.append(x) to add elements to a list, rather than result.add(x).*/

/* C. REWRITTEN PSUEDOCODE: */

def keep_positives(S):
if len(S) == 0:
return []
else:
result = []
for x in S:
if x > 0:
result.append(x)
return result

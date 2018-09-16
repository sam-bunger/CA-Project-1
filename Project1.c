#include <stdio.h>
#include <stdlib.h>

/*
Group number:
9
Team members:
Sam Bunger
Marcus Young
Bite Ye

*/

/* PROJECT 1 */

/* In this assignment you will examine a program consisting of a number of functions - labelled ques1.c to ques15.c -- each of which tests your knowledge of bitwise C operations. Your goal is to determine what each function does and if there
is a simpler way to implement the function. There are two parts to the requirements.  */

/* Assume 32 bit integers */

/* PART A: You need to determine what each function is doing .
You have to determine what each function is doing WITHOUT running the code. You must provide an explanation for your answer - you will get no credit if you correctly identify the function but provide  an incorrect or insufficient/incomplete explanation.
 Once you determine the function, you should run the code to check your answer.
To run the code to test your function, you will need to insert appropriate C code to call the function and print out the result.
 Once you are done showing what each function does, you should then answer part b. */

/* PART B: For each function, can you write a simpler equivalent function in C (using any C operators) that produces the same result.
 By simpler, we are interested in fewer operations in C but also more readable code. */


/*
 As an example, consider the answers to function ques0 - which you worked out in class.

 HANDIN Instructions: You must write out your answers to Part A in a report to be submitted (as a tarfile or zipfile, along with your code) - in addition to the report, you can include comments in your code that may provide a secondary explanation (in case
 your report has errors). You MUST provide an explanation for what the function does and justify your answer. Simply providing an example is NOT an explanation - so don't expect any credit if
 your answers are simply a collection of examples or code comments. You are welcome to provide formal proofs where appropriate, but use your judgement on whether to pursue a formal proof or not. It is preferable to write your answers as comments in the code - but do not feel pressured to do so.
 For part B, write out your code in this file with the answer (a simpler code if it exists) after each of the assigned functions in a manner similar to the example shown in ques0.c (i.e., the answer to function ques7.c should be named ans7.c).

 IMPORTANT: The code you submit must compile correctly (using gcc). If the code you submit does not compile without errors, you will get a zero for Part B of this project.

 GRADING: Each question has a specific number of points (i.e., not all questions have the same level of difficulty). Your grade will be based
 on the correctness of your answer, expressing the answer as a logical function where possible, and the efficiency and readability of your rewritten code.

 Collaboration: You can discuss the project with your teammate. You CANNOT refer to online sources to get help; you can refer to the C syntax documentations. Your report must include names of both members of the team -- failure to do so would imply you are claiming you worked on your own, and may constitute a violation of academic integrity policies.*/

/* EXAMPLE
 this function is similar to CallMeLast in the inclass exercises */
/*  function ques0 returns 1 if x=y and returns 0 if x is not equal to y */
/* the function ans0 does the same in two C statements */


int ques0(int x, int y)
{
    int temp;
    temp = ~y;
    temp = temp + 1;
    temp = temp + x;
    return !(temp);
}

/* Answer to PART B: */
int ans0(int x, int y)
{
    int z = 0;
    if (x == y)  z = 0;
    else z = 1;

    return z;
}

/* QUESTIONS */

/* question 1 */
int ques1(int x)
{
    int z;
    //makes x negative in 2's compliment
    int y  = ~x + 1;
    // if x = 0 - leftmost bit becomes 1
    // else - leftmost bit becomes 0
    z = (~(y | x));
    //leftmost bit becomes rightmost bit
    z = (z >> 31);
    //if the rightmost bit is 0 - 0 is returned
    //else - 1 is returned
    return (z & 1);
}

/*answer to question 1*/
int ans1(int x)
{
    return (x == 0);
}

/* question 2 */
int ques2(int x)
{
    //Make the leftmost bit the rightmost bit, replace the rest with 0
    int mask = x >> 31;
    //bitwise XOR on x and the mask
    //If x is positive, y = x
    //else the leftmost bit of y will be changed.
    int y = (x ^ mask);
    //If the mask = 0, it will remain 0,
    //else it will become all 1s
    int z = (~mask + 1);
    //if x is positive, y+z = y
    //else y+z = the negative 2's compliment of x
    return (y + z);
}

/*answer to question 2*/
int ans2(int x)
{
    return abs(x);
}

/* question 3 */
int ques3(int x)
{
    //Finds if x is 0.
    int y = !x;
    //Finds if x is negative
    int z = x >> 31;
    //finds if x is 0 or negative
    z = z | y;
    //returns 0 if x is 0 or negative.
    return !z;
}

/*answer to question 3*/
int ans3(int x)
{
    return x > 0;
}

/* question 4 */
/* Assume 0 <= n <= 32 */
int ques4(int n)
{
    //Shifts the rightmost bit of n all the way to the left
    //sets it to x
    int x = (!!n) << 31;
    //Shifts the leftmost bit of x all the way to the right,
    //sets it to x
    x = x >> 31;
    //set y to -2147483648
    int y = (1 << 31);
    printf("%d\n", (n + (~0)));
    y = y >> (n + (~0));
    printf("%d\n", y);

    return x & y;
}


/* Answer to question 4*/
int ans4(int n)
{
    n = abs(n) % 64;
    //if(n > 32)
    return -2147483648 / 2;
}


/* question 5 */
<<<<<<< HEAD

int ques5(int x) {
    //leftshift the rightmost bit all 31 spaces, replace with 0s
    int result = (x<<31);
    //Right shift the signed bit, if it was 1 replace with 1s,
    //if it was 0, replace with 0
=======
int ques5(int x)
{
    int result = (x << 31);
    printf("%d\n", result);
>>>>>>> d2b48aa94b0e45e732e44336d30fe88e4e326014
    result = (result >> 31);
    //The result will be all 1s or -1 for odd numbers
    //The result will be all 0s or 0 for even numbers
    return result;
}

/*answer to question 5*/
int ans5(int x){
  return -1*(x%2);
}

/* question 6 */
int ques6(void)
{
    int byte = 0x55;
    int word = byte | byte << 8;

    return word | word << 16;
}


/* question 7 */
int ques7(int x)
{
    return x & (~x + 1);
}


/* question 8 */
int ques8(int x)
{
    int y = x >> 31;
    int z = !!x;

    return y | z;
}

/* question 9 */
int ques9(int x, int n, int c)
{
    int n8 = n << 3;
    int mask = 0xff << n8;
    int cshift = c << n8;
    int z = (x & ~mask);

    return (z  | cshift);
}


/* question 10 */
int ques10(int x)
{
    int y = !!x;
    int z = (!(x + x));

    return y & z;
}


/* question 11 */
int ques11(int x, int y)
{
    int a = x >> 31;
    int b = y >> 31;

    return !((!a & b) | (!(a ^ b) & (y + ~x) >> 31));
}


/* question 12 */
int ques12(int x, int m, int n)
{
    int a = ~m + 1;
    int b = ~x + 1;
    a = x + a;
    b = b + n;

    return !((a | b) >> 31);
}

/* question 13 */
int ques13(int x)
{
    int mask1, mask2, mask4, mask8, mask16;

    mask2 = 0x33 + (0x33 << 8);
    mask2 += mask2 << 16;
    mask1 = mask2 ^ (mask2 << 1);
    mask4 = 0x0F + (0x0F << 8);
    mask4 += mask4 << 16;
    mask8 = 0xFF + (0xFF << 16);
    mask16 = 0xFF + (0xFF << 8);

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}

/* question 14 */
int ques14(int x)
{
    int result = 0;
    int i;

    for (i = 0; i < 32; i++)
        result ^=  (x >> i) & 0x1;

    return result;
}

/* question 15 */
int ques15(int x, int n)
{
    /* for ques15 only, assume n is not a negative number  */
    int temp = (1 << n);
    int z = temp + ~0;

    return (z & x);
}

<<<<<<< HEAD
int test(int y){
  int x = (1 << 31);
  return x >> (y + (~0));
}


int
main(){
=======
int main()
{
>>>>>>> d2b48aa94b0e45e732e44336d30fe88e4e326014
    int a, b;

    int t1;

    printf("Enter first number, an integer stored into variable A preferably between 1 and 20:");
    scanf ("%d", &a);
    printf("\n");
    printf("Enter second number, an integer stored into variable B preferably between 1 and 20:");
    scanf ("%d", &b);
    printf("\n");

    printf("you entered a= %d b= %d  \n", a, b);

<<<<<<< HEAD

	t1=test(a);
	printf("output of ques0 is t1 = %d  \n", t1);
=======
    t1 = ques5(a);
    printf("output of ques0 is t1 = %d  \n", t1);
>>>>>>> d2b48aa94b0e45e732e44336d30fe88e4e326014
    /* To test/run the functions, you will need to input numbers and then call each of the functions, and print the return value */

    return 0;
}

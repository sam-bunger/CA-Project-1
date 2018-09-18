#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    y = y >> (n + (~0));


    return x & y;
}


/* Answer to question 4*/
int ans4(int n)
{
    if(!n){
      return 0;
    }else{
      return -1*(pow(2,(32-n)));
    }
}


/* question 5 */
int ques5(int x)
{
    //leftshift the rightmost bit all 31 spaces, replace with 0s
    int result = (x << 31);
    //Right shift the signed bit, if it was 1 replace with 1s,
    //if it was 0, replace with 0
    result = (result >> 31);
    //The result will be all 1s or -1 for odd numbers
    //The result will be all 0s or 0 for even numbers
    return result;
}

/*answer to question 5*/
int ans5(int x)
{
    return -1 * (x % 2);
}

/* question 6 */
int ques6(void)
{
    // Assign 0x55 to byte
    int byte = 0x55;

    // Let word equal to byte OR (byte shift to left by 8bits)
    int word = byte | byte << 8;

    // Return word OR (word shift to left by 16bits)
    return word | word << 16;
}

/* answer 6 */
int ans6(void)
{
    return 0x55 * 16843009;
}


/* question 7 */
int ques7(int x)
{
    //Return X AND (NOT X plus one)
    return x & (~x + 1);
}

/* answer 7 */
int ans7(int x)
{
    // I don't think there's simpler way to write this function, neither fewer codes or more readable.
    return x & (~x + 1);
}

/* question 8 */
int ques8(int x)
{
    // Let y equal to x shift to right by 31bits. Let y equal to MSB of X.
    int y = x >> 31;

    // Let z equal to NOT(NOT X) <- Logical, not bitwise. Should always be true when X isn't 0.
    int z = !!x;

    // Return y OR Z (bitwise)
    return y | z;
}

/* answer 8 */
int ans8(int x)
{
    if (x == 0) {
        return 0;
    } else if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

/* question 9 */
int ques9(int x, int n, int c)
{
    // Let n8 equal to n times 8
    int n8 = n << 3;

    // Shift 0xff to the left by n8 and assign it to mask
    int mask = 0xff << n8;

    // Shift c to the left by n8 and assign it to cshift
    int cshift = c << n8;

    // Let z equal to X AND NOT MASK
    int z = (x & ~mask);

    // Return z OR cshift
    return (z | cshift);
}

/* answer 9 */
int ans9(int x, int n, int c)
{
    return (x & ~(0xff << (n * 8))) + (c << (n * 8));
}


/* question 10 */
int ques10(int x)
{
    // Let y equal to NOT(NOT X) (logical)
    int y = !!x;

    // Let z equal to NOT(X plus X) (NOT is logical)
    int z = (!(x + x));

    // Return y AND Z
    return y & z;
}

/* answer 10 */
int ans10(int x)
{
    return 0;
}


/* question 11 */
int ques11(int x, int y)
{
    int a = x >> 31;
    int b = y >> 31;

    return !((!a & b) | (!(a ^ b) & (y + ~x) >> 31));
}

/* answer 11 (needs review) */
int ans11(int x, int y)
{
    if (x < y || abs(x) < y || (x < 0 && y > 0) ) return -1;
    else return 0;
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

/* answer 12 */
int ans12(int x, int m, int n)
{
    return (x >= m && n >= x);

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

/* answer 13 */
int ans13(int x)
{
    int bitsOn = 0;
    int i;
    for (i = 0; i < 32; i++) // <32 because there are 0-31 bits.
        if ((x >> i) & 1 == 1) //If the selected bit is on, add 1 to the bitsOn.  
            bitsOn++;
    return bitsOn;
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

/* answer 14 */
int ans14(int x)
{
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    if (count % 2 == 1)
        return 1;
    else
        return 0;

}


/* question 15 */
int ques15(int x, int n)
{
    /* for ques15 only, assume n is not a negative number  */
    int temp = (1 << n);
    int z = temp + ~0;

    return (z & x);
}

/* awnser 15 */
int ans15(int x, int n)
{
    return (x % (1 << n));	//This function returns x modulus 2^n which means it divides x by 2^n and returns the remainder.

}

int main()
{
    int a, b, c;

    int t1;

    printf("Enter first number, an integer stored into variable A preferably between 1 and 20:");
    scanf ("%d", &a);
    printf("\n");
    printf("Enter second number, an integer stored into variable B preferably between 1 and 20:");
    scanf ("%d", &b);
    printf("\n");
    printf("Enter third number, an integer stored into variable C preferably between 1 and 20:");
    scanf ("%d", &c);
    printf("\n");

    printf("you entered a= %d b= %d c= %d \n", a, b, c);


    /* To test/run the functions, you will need to input numbers and then call each of the functions, and print the return value */

    // Q1
    t1 = ques1(a);
    printf("Question1: %d\n", t1);
    t1 = ans1(a);
    printf("Question1 (S): %d\n", t1);

    // Q2
    t1 = ques2(a);
    printf("Question2: %d\n", t1);
    t1 = ans2(a);
    printf("Question2 (S): %d\n", t1);

    // Q3
    t1 = ques3(a);
    printf("Question3: %d\n", t1);
    t1 = ans3(a);
    printf("Question3 (S): %d\n", t1);

    // Q4
    t1 = ques4(a);
    printf("Question4: %d\n", t1);
    t1 = ans4(a);
    printf("Question4 (S): %d\n", t1);


    // Q5
    t1 = ques5(a);
    printf("Question5: %d\n", t1);
    t1 = ans5(a);
    printf("Question5 (S): %d\n", t1);

    // Q6
    t1 = ques6();
    printf("Question6: %x\n", t1);
    t1 = ans6();
    printf("Question6 (S): %x\n", t1);

    // Q7
    t1 = ques7(a);
    printf("Question7: %d\n", t1);
    t1 = ans7(a);
    printf("Question7 (S): %d\n", t1);

    // Q8
    t1 = ques8(a);
    printf("Question8: %d\n", t1);
    t1 = ans8(a);
    printf("Question8 (S): %d\n", t1);

    // Q9
    t1 = ques9(a, b, c);
    printf("Question9: %d\n", t1);
    t1 = ans9(a, b, c);
    printf("Question9 (S): %d\n", t1);


    // Q10
    t1 = ques10(a);
    printf("Question10: %d\n", t1);
    t1 = ans10(a);
    printf("Question10 (S): %d\n", t1);

    //Q11
    t1 = ques11(a, b);
    printf("Question11: %d\n", t1);
    t1 = ans11(a, b);
    printf("Question11 (S): %d\n", t1);

    //Q12
    t1 = ques12(a, b, c);
    printf("Question12: %d\n", t1);
    t1 = ans12(a, b, c);
    printf("Question12 (S): %d\n", t1);

    //Q13
    t1 = ques13(a);
    printf("Question13: %d\n", t1);
    t1 = ans13(a);
    printf("Question13 (S): %d\n", t1);

    //Q14
    t1 = ques14(a);
    printf("Question14: %d\n", t1);
    t1 = ans14(a);
    printf("Question14 (S): %d\n", t1);

    //Q15
    t1 = ques15(a, b);
    printf("Question15: %d\n", t1);
    t1 = ans15(a, b);
    printf("Question15 (S): %d\n", t1);


    return 0;
}

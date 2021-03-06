//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Ian Altoveros
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: To evaluate post-fix expressions.
//Algorithm: Read an Item, If it is a number push into the stack. If it is an operator pop it into the stack.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result;
  int resultt;
  int leftover;
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  // ** 
	  if( (item >= '0') && (item <= '9'))
	    { 
        cout << "Pushing in " << item << endl;
	      postfixstack.push(item - '0');
	    }
	  

	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
        cout << "Applying " << item << " to the operands" << endl;
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') 
        {   
            result = box2-box1;
        }
	      if (item == '+')
        {
          cout << "Adding " << box2 << " to " << box1<< endl;
          result = box2+box1;
        }
	      if (item == '*')
        {
          result = box2*box1;
        }
	      // ** also do the + and * cases 
	      // ** Finally push the result
        cout << "Pushing in " << result << " as a result" << endl;
	      postfixstack.push(result);

	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // E    rror messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{   
	  cout << "Stack Overflow! Expression is too long " << endl;
          }
        catch (stack::Underflow) // for too few operands
	{ 
	  cout << "Stack Underflow! Too few operands " << endl;
        }
      catch (char const* errorcode) // for invalid item
	{ 
        cout << "Invald character" << endl;
       
      }
      // go back to the loop after incrementing i
    i++;
     
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.

  postfixstack.pop(resultt);
  cout << "The result is " << resultt << endl;

  if(!postfixstack.isEmpty())
    {
      cout << " An incomplete expression was found! " << endl;
    }

  cout  << " END OF PROGRAM " << endl;
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.

  
   

}// end of the program

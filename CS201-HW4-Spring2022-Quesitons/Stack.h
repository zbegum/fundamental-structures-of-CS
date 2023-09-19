
/************************************************************************
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201-01
 *  HW-4
 *
 *  The header file of a pointer based implementation of stack class
 *  retrived from 2005, Pearson Addison-Wesley
 ************************************************************************/
#include <iostream>
using namespace std;

class Stack{

public:
   Stack();
   Stack(const Stack& aStack);
   ~Stack();

   bool isEmpty() const;
   bool push(double newItem);
   bool pop();
   bool pop(double& stackTop);
   bool getTop(double& stackTop) const;
   void printStack() const;

private:
   struct StackNode {            // a node on the stack
      double item;        // a data item on the stack
      StackNode    *next;        // pointer to next node
   };

   StackNode *topPtr;     // pointer to first node in the stack
};

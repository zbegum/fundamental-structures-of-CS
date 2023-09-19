
/************************************************************************
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201-01
 *  HW-4
 ************************************************************************/

 #include <iostream>
 #include <sstream>
 #include "Solutions.h"
 #include "Stack.h"

 using namespace std;


void fantabulous(string list, int length){
     Stack* initialList = new Stack();
     int numOfFantabulous = 0;

     //create initial stack from string list
     int firstIndex = 0;
     double temp = 0;
     std::stringstream convert;
     for(int i = 0; i < list.length(); i++){
        if(list[i] == ',' || i + 1 == list.length()){
            convert << list.substr(firstIndex, i);
            convert >> temp;
            convert.str(""); // clear the stringstream
            convert.clear();
            initialList->push(temp);
            firstIndex = i + 1;
        }
     }

     //generate sublists of initial stack
     Stack* rootList;
     Stack* tempList;
     double maxElement;
     double secondMaxElement;
     bool validInsertion;

     while (!initialList->isEmpty()){
         rootList = new Stack(*initialList);
         tempList = new Stack();

         //insert first element to new stack
         rootList->pop(temp);
         maxElement = temp;
         secondMaxElement = temp;
         tempList->push(temp);
         validInsertion = true;

         //insert rest of it
         while(!rootList->isEmpty()){
            rootList->pop(temp);

            if (temp < maxElement && temp > secondMaxElement){
                secondMaxElement = temp;
                validInsertion = true;
            }

            else if (temp > maxElement){
                secondMaxElement = maxElement;
                maxElement = temp;
                validInsertion = false;
            }

            if(validInsertion){ numOfFantabulous++; }

            tempList->push(temp);
         }

         initialList->pop();

         delete tempList;
         delete rootList;
     }

     delete initialList;

     cout << "The number of Fantabulous subsequences: " << numOfFantabulous << endl;
 }

void subset(string intervals, int length){
    Stack* openingStack = new Stack();
    Stack* closingStack = new Stack();

    int num = 0;
     int firstIndex = 0;
     double temp = -2;
     cout << "Joined subsets: ";

     double topOpening = -1;
     double topClosing = -1;
     std::stringstream convert;
     for(int i = 0; i < intervals.length(); i++){
        //extract number from string
        //assumed first indexes of subsets is in increasing order
        if(intervals[i] == ',' || i + 1 == intervals.length()){
            num++;
            convert << intervals.substr(firstIndex, i);
            convert >> temp;
            convert.str(""); // clear the stringstream
            convert.clear();
            firstIndex = i + 1;

            if( num % 2 == 1){
                if(openingStack->isEmpty()){ openingStack->push(temp); }
                else{
                    openingStack->getTop(topOpening);
                    if (closingStack->getTop(topClosing) && topClosing < temp) { //disjoint
                        cout << "(" << topOpening << ":" << topClosing << "), ";
                        openingStack->pop();
                        closingStack->pop();
                        openingStack->push(temp);
                    }
                }
            }
            else if ( num % 2 == 0){
                if(closingStack->isEmpty()){ closingStack->push(temp);}
                else{
                    closingStack->getTop(topClosing);
                    if (topClosing < temp) { //disjoint
                        closingStack->pop();
                        closingStack->push(temp);
                    }
                }
            }

            //returning last interval in stack
            if(i + 1 == intervals.length()){
                openingStack->getTop(topOpening);
                closingStack->getTop(topClosing);
                cout << "(" << topOpening << ":" << topClosing << ") " << endl;
                openingStack->pop();
                closingStack->pop();
            }
        }
     }
     delete openingStack;
     delete closingStack;
}

string infix2prefix(string expression){
    Stack* tempStack = new Stack();
    int temp; //asciiVal
    double topVal;

    string tempStr = "";
    string reversedExpression = "";


    //reverse expression
    for(int i = 0; expression[i] != '\0'; i++){
        temp = expression[i];
        tempStack->push(temp);
    }
    while(!tempStack->isEmpty()){
        tempStack->getTop(topVal);
        if(topVal == 40) {tempStr = ")";}
        else if (topVal == 41){tempStr = "(";}
        else{ tempStr = (char)topVal;}
        reversedExpression = reversedExpression.append(tempStr);
        tempStack->pop();
    }

    Stack* operatorStack = new Stack();

    //convert reversed infix to postfix
    tempStr = "";
    string postRes = "";
    for(int i = 0; reversedExpression[i] != '\0'; i++){
        temp = reversedExpression[i];

        if(isOperand(temp)){
            tempStr = (char)temp;
            postRes = postRes.append(tempStr);
        }
        else if( temp == 40 ){ //'('
            operatorStack->push(temp);
        }
        else if ( temp == 41 ){ //')'
            operatorStack->getTop(topVal);
            while(topVal != 40){
                tempStr = (char)topVal;
                postRes = postRes.append(tempStr);
                operatorStack->pop();
                operatorStack->getTop(topVal);
            }
            operatorStack->pop();
        }
        else{ //is operator
            operatorStack->getTop(topVal);
            while(!operatorStack->isEmpty() && topVal != 40 && isPrecedent(temp, topVal)){
                tempStr = (char)topVal;
                postRes = postRes.append(tempStr);
                operatorStack->pop();
                operatorStack->getTop(topVal);
            }
            operatorStack->push(temp);
        }
    }

   while(!operatorStack->isEmpty()){
        operatorStack->getTop(topVal);
        tempStr = (char)topVal;
        postRes = postRes.append(tempStr);
        operatorStack->pop();
    }

    //reverse expression
    for(int i = 0; postRes[i] != '\0'; i++){
        temp = postRes[i];
        tempStack->push(temp);
    }

    reversedExpression = "";
    while(!tempStack->isEmpty()){
        tempStack->getTop(topVal);
        if(topVal == 40) {tempStr = ")";}
        else if (topVal == 41){tempStr = "(";}
        else{ tempStr = (char)topVal;}
        reversedExpression = reversedExpression.append(tempStr);
        tempStack->pop();
    }

    delete tempStack;
    delete operatorStack;
    return reversedExpression;
}

void evaluatePrefix(string expression){
    Stack* charStack = new Stack();
    double expAdded;
    double temp = 0;
    double tempOperator = 0;

    for(int i = 0; expression[i] != '\0'; i++){
        expAdded = expression[i];

        if(!charStack->getTop(temp)) { charStack->push(expAdded); }
        else {

            while( isOperand(expAdded) && isOperand(temp)){

                charStack->pop();
                charStack->pop(tempOperator);

                temp = temp - 48;
                expAdded = expAdded - 48;

                if (tempOperator == 43 ){ expAdded = temp + expAdded; }
                else if (tempOperator == 45) { expAdded = temp - expAdded; }
                else if (tempOperator == 42) { expAdded = temp * expAdded; }
                else if(tempOperator == 47) { expAdded = temp / expAdded; }

                expAdded = expAdded + 48;
                charStack->getTop(temp);
            }
            charStack->push(expAdded);
        }
    }
    cout << "Result of " << expression << " is " << expAdded - 48 << endl;
    delete charStack;
}

bool isOperand(int asciiVal){ return 47 < asciiVal; }

bool isPrecedent(int op1, int op2){
    if((op1 == 42 || op1 == 47) && (op2 == 43 || op2 == 45)) {return false;}
    else{ return true; }
}



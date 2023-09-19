/************************************************************************
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201-01
 *  HW-3
 ************************************************************************/

 #include <iostream>
 using namespace std;
 #include "PuzzleContainer.h"

PuzzleRow::PuzzleRow( int size, int rowindex) {
    head = NULL;
    currentSize = 0;
    maxSize = size;
    next = NULL;
    this->rowindex = rowindex;
}

PuzzleRow::~PuzzleRow(){
    while (!isEmpty())
    remove(1);
}

int PuzzleRow::getRowIndex() { return rowindex; }

int PuzzleRow::getCurrentSize() { return currentSize; }

void PuzzleRow::setNext( PuzzleRow* next ) { this->next = next; };

PuzzleRow* PuzzleRow::getNext() { return next; }

bool PuzzleRow::insert( int index, unsigned char shape ){
    if(currentSize + 1 > maxSize || index < 1 || maxSize < index)
        return false;

    PuzzlePiece* newPiecePtr = new PuzzlePiece;
    newPiecePtr->shape = shape;
    newPiecePtr->colindex = index;
    newPiecePtr->rowindex = rowindex;

    newPiecePtr->next = head;
    head = newPiecePtr;

    currentSize++;
    return true;
}

bool PuzzleRow::remove( int index ){
    PuzzlePiece *temp;
    if (index < 1 || index > maxSize){
        return false;
    }

    int num = 1;
    PuzzlePiece* searchingPtr = head;
    for(int i = 1; i <= currentSize; i++){
        if(searchingPtr->colindex == index){
            num = i;
            break;
        }
    }

    if (num == 1){
        temp = head;
        head = head->next;
    }
    else{
        PuzzlePiece *prev = head;
        for (int i = 1; i < num; i++)
            prev = prev->next;

        temp = prev->next;
        prev->next = temp->next;
    }

    temp->next = NULL;
    delete temp;
    temp = NULL;

    currentSize--;
    return true;
}

bool PuzzleRow::isEmpty() { return currentSize == 0; }

unsigned char PuzzleRow::getPiece( int index ) {

    PuzzlePiece* searchingPtr = head;
    for(int i = 1; i <= currentSize; i++){
        if(searchingPtr->colindex == index){
            return searchingPtr->shape;
        }
        searchingPtr = searchingPtr->next;
    }

    return 225;
}

void PuzzleRow::printRow(){
    PuzzlePiece* printerPtr;
    for (int j = 1; j <= maxSize; j++){
        if(getPiece(j) != 225) {cout << "X ";}
        else {cout << "O ";}
    }
    cout << endl;
}

void shapeConverter(unsigned char shape, int& down, int& up, int& right, int& left){
    down = shape%4;
    up = (shape/4)%4;
    right= (shape/16)%4;
    left= shape/64;
}

//--------------puzzle container------------------
PuzzleContainer::PuzzleContainer( int h, int w ){
    rowLists = NULL;
    length = 0;
    height = h;
    width = w;

    for(int indexRow = 1; indexRow <= height; indexRow++){
        insertRow(indexRow);
    }
}

PuzzleContainer::~PuzzleContainer(){
    for(int indexRow = height; indexRow >= 1; indexRow--){
        removeRow(indexRow);
    }
}

PuzzleRow* PuzzleContainer::getRow( int index ){
    if (index < 1 || index > length){
        return NULL;
    }

    PuzzleRow* searchingPtr = rowLists;
    for(int i = 1; i < index; i++)
        searchingPtr = searchingPtr->getNext();

    return searchingPtr;
}

bool PuzzleContainer::insertRow( int index ){
     if(length + 1 > height || index < 1 || height < index)
        return false;

    PuzzleRow* newRowPtr = new PuzzleRow(width, index);

    if (index == 1){
        newRowPtr->setNext(rowLists);
        rowLists = newRowPtr;
    }
    else{
        PuzzleRow *lastRow = rowLists;
        for (int i = 1; i < index-1; i++)
            lastRow = lastRow->getNext();

        newRowPtr->setNext(lastRow->getNext());
        lastRow->setNext(newRowPtr);
    }

    length++;
    return true;
}

bool PuzzleContainer::removeRow( int index ){
    PuzzleRow *temp;
    if (index < 1 || index > length)
        return false;

    if (index == 1){
        temp = rowLists;
        rowLists = rowLists->getNext();
    }
    else{
        PuzzleRow *prev = rowLists;
        for (int i = 1; i < index - 1; i++)
            prev = prev->getNext();

        temp = prev->getNext();
        prev->setNext(temp->getNext());
    }

    temp->setNext(NULL);
    delete temp;
    temp = NULL;

    length--;
    return true;
}

bool PuzzleContainer::addPiece( int row, int col , unsigned char shape ){
    if(col > width || col < 1 || row > height || row < 1){
        cout << "(" << row << "," << col << ") is out of frame, it cannot be added" << endl;
        return false;
    }
    else if(getRow(row)->getPiece(col) != 225){
        cout << "(" << row << "," << col << ") has been already occupied, it cannot be added" << endl;
        return false;
    }
    else if(!doesFit(row, col , shape )){
        cout << "Shape doesn’t fit into (" << row << "," << col << "), it cannot be added" << endl;
        return false;
    }
    else{
        getRow(row)->insert(col, shape);
        cout << "A piece is added to (" << row << "," << col << ")" << endl;
        return true;
    }

}

bool PuzzleContainer::removePiece(int row, int col){
    if(col > width || col < 1 || row > height || row < 1){
        cout << "(" << row << "," << col << ") is out of frame, it cannot be removed" << endl;
        return false;
    }
    else if(getRow(row)->getPiece(col) == 225){
        cout << "There is no piece on (" << row << "," << col << "), it cannot be removed" << endl;
        return false;
    }
    else{
        getRow(row)->remove(col);
        cout << "The piece on (" << row << "," << col << ") is removed" << endl;
        return true;
    }
}

bool PuzzleContainer::doesFit(int row, int col , unsigned char shape){
    int down;
    int up;
    int right;
    int left;

    int tempDown;
    int tempUp;
    int tempRight;
    int tempLeft;

    shapeConverter(shape, down, up, right, left);

    //borders to inside
    if(down == 2 && row != getHeight()) { return false; }
    if(up == 2 && row != 1) { return false; }
    if(right == 2 && col != getWidth()) { return false; }
    if(left == 2 && col != 1) { return false; }

    //others to border
    if(down != 2 && row == getHeight()) { return false; }
    if(up != 2 && row == 1) { return false; }
    if(right != 2 && col == getWidth()) { return false; }
    if(left != 2 && col == 1) { return false; }

    //next
    if(col != width && getRow(row)->getPiece(col + 1) != 225){
        shapeConverter(getRow(row)->getPiece(col + 1), tempDown, tempUp, tempRight, tempLeft);
        if(right == tempLeft) { return false; }
    }
    //prev
    if(col != 1 && getRow(row)->getPiece(col - 1) != 225){
        shapeConverter(getRow(row)->getPiece(col - 1), tempDown, tempUp, tempRight, tempLeft);
        if(left == tempRight) { return false; }
    }
    //down
    if(row != height && getRow(row + 1)->getPiece(col) != 225){
        shapeConverter(getRow(row + 1)->getPiece(col), tempDown, tempUp, tempRight, tempLeft);
        if(down == tempUp) { return false; }
    }
    //up
    if(row != 1 && getRow(row - 1)->getPiece(col) != 225){
        shapeConverter(getRow(row - 1)->getPiece(col), tempDown, tempUp, tempRight, tempLeft);
        if(up == tempDown) { return false; }
    }

    return true;
}

int PuzzleContainer::getHeight(){ return height; }

int PuzzleContainer::getWidth() { return width; }

void PuzzleContainer::showPiece(int row, int col){
    if(col > width || col < 1 || row > height || row < 1){
        cout << "(" << row << "," << col << ") is out of frame, it cannot be shown" << endl;
    }
    else if(getRow(row)->getPiece(col) == 225) {
        cout << "There is no piece on (" << row << "," << col << "), it cannot be shown" << endl;
    }
    else{
        cout << "Piece on (" << row << "," << col << ") as following:" << endl;
        int down, up, right, left;
        unsigned char myPiece = getRow(row)->getPiece(col);
        shapeConverter(myPiece, down, up, right, left);
        cout << "Down: ";
        shapePrinter(down);
        cout << "Up: ";
        shapePrinter(up);
        cout << "Right: ";
        shapePrinter(right);
        cout << "Left: ";
        shapePrinter(left);
    }
}

void PuzzleContainer::displayContainer(){
    cout << "Container " << height << "x" << width << ":" << endl;

    cout << "   ";
    for (int i = 1; i <= width; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i <= height; i++){
        cout << i << "  ";
        getRow(i)->printRow();
    }
}

void PuzzleContainer::showColumn(int col){
    if(col > width || col < 1){
        cout << "Column " << col << " is out of border" << endl;
    }
    else{
        PuzzleRow* temp;
        cout << "Column " << col << ":" << endl;
        for(int i = 1; i <= height; i++){
            temp = getRow(i);
            if(temp->getPiece(col) == 225)
                cout << "O" << endl;
            else
                cout << "X" << endl;

        }
    }
}

void PuzzleContainer::showRow(int row){
    if(row > height || row < 1){
        cout << "Row " << row << " is out of border" << endl;
    }
    else{
        cout << "Row " << row << ":" << endl;
        getRow(row)->printRow();
    }
}

void PuzzleContainer::findPiece(unsigned char shape){
    int targetDown;
    int targetUp;
    int targetRight;
    int targetLeft;

    int down;
    int up;
    int right;
    int left;

    bool thereExists = false;

    shapeConverter(shape, targetDown, targetUp, targetRight, targetLeft);

    for(int h = 1; h <= height; h++){
        for(int w = 1; w <= width; w++){
            shapeConverter(getRow(h)->getPiece(w), down, up, right, left);
            if (down == targetDown && up == targetUp && right == targetRight && left == targetLeft){
                cout << "(" << h << "," << w << ") ";
                thereExists = true;
            }
        }
    }
    if (thereExists) { cout << "contain the piece that has shape" << endl; }
    else{ cout << "There is no piece that has shape" << endl; }
    cout << "Down: ";
    shapePrinter(targetDown);
    cout << "Up: ";
    shapePrinter(targetUp);
    cout << "Right: ";
    shapePrinter(targetRight);
    cout << "Left: ";
    shapePrinter(targetLeft);

}

void PuzzleContainer::shapePrinter(int direction){
    if(direction == 0)
        cout << "Hole" << endl;
    else if(direction == 1)
        cout << "Knob" << endl;
    else
        cout << "Border"<< endl;
}



/************************************************************************
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201-01
 *  HW-3
 ************************************************************************/

class PuzzleRow{

private:
    struct PuzzlePiece{
        unsigned char shape;
        int rowindex;
        int colindex;
        PuzzlePiece* next;
    };

    PuzzlePiece* head;
    PuzzleRow* next;
    int rowindex;
    int currentSize;
    int maxSize; //equals to puzzleContainer width

public:
    PuzzleRow( int size, int rowindex);
    ~PuzzleRow();
    int getRowIndex();
    int getCurrentSize();
    void setNext( PuzzleRow* next );
    PuzzleRow* getNext();
    bool insert( int index, unsigned char shape );
    bool remove( int index );
    bool isEmpty();
    unsigned char getPiece( int index );
    void printRow();
};

class PuzzleContainer{

private:
    PuzzleRow* rowLists;
    int height;
    int width;
    int length;

public:
    PuzzleContainer(int h, int w);
    ~PuzzleContainer();
    PuzzleRow* getRow( int index );
    bool insertRow( int index );
    bool removeRow( int index );
    bool addPiece( int row, int col , unsigned char shape );
    bool doesFit(int row, int col , unsigned char shape);
    bool removePiece(int row, int col);
    int getHeight();
    int getWidth();
    void showPiece(int row, int col);
    void shapePrinter(int direction);
    void displayContainer();
    void showColumn(int col);
    void showRow(int row);
    void findPiece(unsigned char shape);
};

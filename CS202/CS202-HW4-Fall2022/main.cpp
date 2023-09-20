/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : This program constructs a Red Black Tree from given input.txt and converts it to a 2-3-4 Tree
*               displays the converted tree in output.txt file
*/

#include "TwoThreeFourTree.h"

int main(int argc, char** args){

    int rootNodeItem;
    int numOfNodes;
    int dataItem, dataLeftItem, dataRightItem, dataColor;
    int MAX_SIZE = 1000;
    NodeData* data[MAX_SIZE];
    int sizeOfNodes = 0;

    string filename(args[1]);
    int number;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "Could not open the file - '" << filename << "'" << endl;
    }
    int i = 0;
    while (input_file >> number) {
        if(i == 0){
            numOfNodes = number;
        }
        else if (i == 1){
            rootNodeItem = number;
        }
        else{
            if ((i - 2) % 4 == 0){ dataItem = number; }
            else if ((i - 2) % 4 == 1) { dataLeftItem = number; }
            else if ((i - 2) % 4 == 2) { dataRightItem = number; }
            else {
                dataColor = number;
                data[sizeOfNodes] = new NodeData(dataItem, dataLeftItem, dataRightItem, dataColor);
                sizeOfNodes++;
            }
        }
        i++;
    }

    input_file.close();

    RBTree* rbtree = new RBTree();
    rbtree->constructTree(rootNodeItem, data, numOfNodes);

    TwoThreeFourTree* ttfTree = new TwoThreeFourTree();
    ttfTree->construct234Tree(rbtree->root);
    int num = 0;
    ttfTree->traverse(ttfTree->root, num);     // num counts the number of nodes in 234 tree and index of root is always 0
    ttfTree->printInorder(ttfTree->root);

    ofstream outfile;
    outfile.open(args[2]);
    outfile << num << "  0" << endl;
    string res = "";
    ttfTree->out(ttfTree->root, res);
    outfile << res;
    outfile.close();

return 0;
}

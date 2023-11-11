// C++ program for sparse matrix representation.
// Using Link list 

#include <iostream>
#include <vector>

using namespace std;

// Node class to represent link list
class Node
{
	public:
	int row;
	int col;
	int data;
	Node *next;
};

// Function to create new node
void create_new_node(Node **p, int row_index,
					int col_index, int value)
{
	Node *temp = *p;
	Node *x;
	
	
	if (temp == NULL)
	{
		temp = new Node();
		temp->row = row_index;
		temp->col = col_index;
		temp->data = value;
		temp->next = NULL;
		*p = temp;
	}
	
	
	else
	{
		while (temp->next != NULL) 
			temp = temp->next;
			
		x = new Node();
		x->row = row_index;
		x->col = col_index;
		x->data = value;
		x->next = NULL;
		temp->next = x;
	}
}

// Function prints contents of linked list

void printList(Node *start)
{
	Node *ptr = start;
	cout << "row_position:";
	while (ptr != NULL)
	{
		cout << ptr->row << " ";
		ptr = ptr->next;
	}
	cout << endl;
	cout << "column_position:";

	ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->col << " ";
		ptr = ptr->next;
	}
	cout << endl;
	cout << "Value:";
	ptr = start;
	
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}




int main() {
    int rows, cols;

    // Input the number of rows and columns
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    
    vector<vector<int>> sparseMatrix(rows, vector<int>(cols));

    // Input the matrix elements row-wise with spaces
    cout << "Enter the matrix elements row-wise (separated by spaces):" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j) {
            cin >> sparseMatrix[i][j];
        }
    }
   

    // Display the entered matrix
    cout << "\nEntered Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }
    Node *first = NULL;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			
			// Pass only those values which 
			// are non - zero
			if (sparseMatrix[i][j] != 0)
				create_new_node(&first, i, j, 
								sparseMatrix[i][j]);
		}
	}
	printList(first);


    return 0;
}

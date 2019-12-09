# A general description of the system

The system is divided into a number of sub-sections such as, project creation, material
creation, crew creation, and a BST (Binary search tree) section.
Project creation consists of a Project class that stores the key information for every
new project in variables such as title, summary, genre etc. It has member functions
such as setProjectStatus which uses a switch statement to change the project status
from released, to unreleased, to now playing. This is important as project information
can only be added when the status of the project is released, and ticket sales can only
be added when the project status is now playing.
The class also has a getVectorData member function which prompts the user for the
correct information and passes it to the respective variables using the class
parameterized constructor. It then adds the object instance to a vector creating a
vector of objects (this allows for the creation of multiple projects). Lastly, the class has
anotherObject member function which prompts the user to add another project, and the
displayVector member function which displays all the acquired data about the projects.
Similar to the project creation section, the material creation section also utilises a
Material class with a parameterized constructor and member functions to prompt the
user for data, prompt the user to create another material, and to display the acquired
data. The difference with the material section however, is that the Material class has
private accessor functions which are used in the displayVector member function to call
the variables from the class and correctly display the respective data. Another
difference is also that the Material class is a base class and has a derived class called
mType, the derived class has 2 member functions, one to prompt the user for the
material type and the other to retrieve the correct packaging specifications based on
the material type.
Lastly of the classes, there is the Crew class. It operates in the same manner as the
Project and Material class, having 3 main member functions which prompt the user for
crew data, prompts the user to create another crew instance and then displays the
acquired data.
The BST section is composed of a Node struct with a type long double variable and
two pointers to Node, to store left and right child’s address. It has functions to create a
new node, insert a value in the tree, search for a specific value, view the values in the
tree and delete values from the tree.

# Data structures used

The binary search tree was used due to its efficiency in being both a data structure and a
search algorithm.
All the nodes are created in dynamic memory and therefore can only be accessed using a
pointer.
To access the tree a pointer to Node variable called rootPtr is created and set it to NULL
(empty tree). This variable points to the address of the root and allows the traversal of the
tree.
The function getNewNode takes a long double value as a parameter and creates a Node in
the heap memory using the new operator and returns the new Node.
The insert function utilises recursion by taking a rootPtr (address of the root) and value to be
inserted as parameters and should the root be empty it calls the getNewNode function to the
rootPtr. If however a root exists already and the data to be inserted is greater than the root, it
is inserted to the right subtree of the root. And if it is less than the value of the root, it is
inserted to the left subtree of the root.
15
The search function is a boolean type that takes the rootPtr (address of the root) and the
value to be searched as parameters. It returns false if the root is equal to 0, if the value of the
root is equal to the value the function is searching for. Then it returns true. If it isn’t, and the
value is less than that of the root, then recursion is utilised and the function calls itself with the
left subtree passed as the first parameter and the same value passed as the second. The
same applies to if the value is higher than the root’s, except the right subtree is passed as a
parameter instead.
The displayPreOrder function displays the data stored in the search tree as long as the root is
not empty.
The deleteNode and makeDeletion functions are used to delete nodes from the search tree.
The deleteNode function utilises recursion and takes the number to be deleted and the rootPtr
as a parameter. Should the value at the root be lower than the value to be deleted, it calls
itself with the same value to be deleted as a first parameter, and the left subtree of the root as
the second parameter. Vice-versa for if the value is higher. If the value of the node is equal to
the value to be deleted. Then the function makeDeletion is called with the parameter of the
address of the node to be deleted.
The makeDeletion function first creates a temporary node pointer of type Node, then it checks
if the node is empty and displays an error message if it is. If it is not, and the value to be
deleted has another value to it’s right, it assigns the current value to the temporary node
pointer and then assigns the value to the right to the rootPtr. It then deleted the temporary
node pointer. Vice versa for if it has a value to it’s left

# Notes

System is functional and serves its purpose but is incomplete in some aspects and lacks a GUI. 

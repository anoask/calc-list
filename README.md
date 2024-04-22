# CalcList
A calculator implementation in C++ using a singly linked list to keep track of operations and their results

Header Files and Classes
  CalcList.hpp and CalcListInterface.hpp:
  CalcList.hpp contains the CalcList class that implements the calculator's functionality.
  CalcListInterface.hpp is an abstract class defining the interface for the calculator with virtual functions that must be implemented by any derived class.

Key Components
  Node Structure:
    Defined in CalcList.hpp, it holds individual calculator operations. Each node stores the operation type (FUNCTIONS enum with operations like addition, subtraction, etc.), the       operand for that operation, the result after the operation (totalAtStep), and a pointer to the next node.
  CalcList Class:
    Inherits from CalcListInterface.
    Manages operations using a singly linked list where each node represents a calculation step.
    Contains methods to perform operations (newOperation), undo the last operation (removeLastOperation), get the current total (total), and a string representation of all              operations (toString).

Core Methods
  Constructor and Destructor:
    The constructor initializes an empty list and other properties.
    The destructor cleans up dynamically allocated nodes to prevent memory leaks.
  total():
    Returns the current result of all operations performed so far.
  newOperation():
    Takes an operation type and an operand, performs the operation on the current total, and adds a new node to the linked list to record this step.
  removeLastOperation():
    Removes the most recent operation, updating the list and recalculating the total from the remaining operations.
  toString():
    Returns a string representation of all operations in reverse order (latest first), formatted with a specified precision. This helps visualize the sequence of operations and         their results.
  Error Handling
    Throws exceptions for invalid operations like division by zero or attempting to remove an operation from an empty list.
  Test Suite
    Uses Catch2 for unit testing.
    Tests include checking initial conditions, the functionality of adding and removing operations, proper error handling, and output formatting.

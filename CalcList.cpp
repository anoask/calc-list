#include "CalcList.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

CalcList::CalcList() : head(nullptr), currentTotal(0), numOperations(0) {}

CalcList::~CalcList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

double CalcList::total() const {
    return currentTotal;
}

void CalcList::newOperation(const FUNCTIONS func, const double operand) {
    double result = 0;
    switch (func) {
        case ADDITION:
            result = currentTotal + operand;
            break;
        case SUBTRACTION:
            result = currentTotal - operand;
            break;
        case MULTIPLICATION:
            result = currentTotal * operand;
            break;
        case DIVISION:
            if (operand == 0) {
                throw std::invalid_argument("Division by zero is not allowed.");
            }
            result = currentTotal / operand;
            break;
        default:
            throw std::invalid_argument("Invalid operation.");
    }

    // Create a new node and update currentTotal
    // Reverse the order of nodes to maintain the correct order
    head = new Node(func, operand, result, head);
    currentTotal = result;
    numOperations++;
}


void CalcList::removeLastOperation() {
    if (head == nullptr) {
        throw std::runtime_error("Cannot remove operation from an empty CalcList.");
    }

    Node* temp = head;
    head = head->next;
    currentTotal = (head == nullptr) ? 0 : head->totalAtStep;
    delete temp;
    numOperations--;
}

std::string CalcList::toString(unsigned short precision) const {
    std::ostringstream oss;
    Node* current = head;
    int step = numOperations;

    while (current != nullptr) {
        oss << step << ": ";

        double nextTotalAtStep = (current->next != nullptr) ? current->next->totalAtStep : 0.0;

        if (current->func == ADDITION || current->func == SUBTRACTION) {
            // For addition and subtraction, use the totalAtStep value from the next node
            oss << std::fixed << std::setprecision(precision) << nextTotalAtStep;
        } else {
            // For multiplication and division, use the totalAtStep value of the current node
            oss << std::fixed << std::setprecision(precision) << current->totalAtStep;
        }

        switch (current->func) {
            case ADDITION:
                oss << "+";
                break;
            case SUBTRACTION:
                oss << "-";
                break;
            case MULTIPLICATION:
                oss << "*";
                break;
            case DIVISION:
                oss << "/";
                break;
        }

        oss << std::fixed << std::setprecision(precision) << current->operand;
        oss << "=" << current->totalAtStep << "\n";

        current = current->next;
        step--;
    }

    return oss.str();
}


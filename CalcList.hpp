#ifndef CALCLIST_H
#define CALCLIST_H

#include "CalcListInterface.hpp"

// Node structure for the singly linked list
struct Node {
    FUNCTIONS func;
    double operand;
    double totalAtStep;
    Node* next;

    Node(FUNCTIONS f, double op, double total, Node* n = nullptr)
            : func(f), operand(op), totalAtStep(total), next(n) {}
};

class CalcList : public CalcListInterface {
private:
    Node* head;
    double currentTotal;
    int numOperations;

public:
    CalcList(); // Constructor
    ~CalcList(); // Destructor

    double total() const override;
    void newOperation(const FUNCTIONS func, const double operand) override;
    void removeLastOperation() override;
    std::string toString(unsigned short precision) const override;
};

#endif /* CALCLIST_H */

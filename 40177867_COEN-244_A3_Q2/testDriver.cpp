#include "BaseTensor.h"
#include "RankOneTensor.h"
#include "RankTwoTensor.h"
#include "Utility.h"
#include <iostream>

void testIncrementOperatorRankOne(); 
void testIncrementOperatorRankTwo();
void testAddOperatorRankOne(); 
void testAddOperatorRankTwo();
void testAddOperatorRankOne();
void testAddOperatorRankTwo();
void testAssignmentOperatorRankOne(); 
void testAssignmentOperatorRankTwo();
void testCoutStreamOperatorRankOne();
void testCoutStreamOperatorRankTwo();
void testCinStreamOperatorRankOne();
void testCinStreamOperatorRankTwo();
void testIndexOperatorRankOne();
void testIndexOperatorRankTwo();

int main() {
    charLine();
    testIncrementOperatorRankOne();
    charLine();
    testIncrementOperatorRankTwo();
    charLine();
    testAddOperatorRankOne();
    charLine();
    testAddOperatorRankTwo();
    charLine();
    testAddOperatorRankOne();
    charLine();
    testAddOperatorRankTwo();
    charLine();
    testAssignmentOperatorRankOne();
    charLine();
    testAssignmentOperatorRankTwo();
    charLine();
    testCoutStreamOperatorRankOne();
    charLine();
    testCoutStreamOperatorRankTwo();
    charLine();
    testCinStreamOperatorRankOne();
    charLine();
    testCinStreamOperatorRankTwo();
    charLine();
    testIndexOperatorRankOne();
    charLine();
    testIndexOperatorRankTwo();
    charLine();

    return 0;
}


// Test increment operator for RankOneTensor
void testIncrementOperatorRankOne() {
    RankOneTensor t(5);
    t.loadData();

    std::cout << "RankOneTensor before increment: " << t << std::endl;

    std::cout << "RankOneTensor after prefix increment: " << ++t << std::endl;

    t++;
    std::cout << "RankOneTensor after postfix increment: " << t << std::endl;
}

// Test increment operator for RankTwoTensor
void testIncrementOperatorRankTwo() {
    RankTwoTensor t(3, 3);
    t.loadData();

    std::cout << "RankTwoTensor before increment: " << t << std::endl;

    std::cout << "RankTwoTensor after prefix increment: " << ++t << std::endl;

    t++;
    std::cout << "RankTwoTensor after postfix increment: " << t << std::endl;
}

// Test addition operator for RankOneTensor
void testAddOperatorRankOne() {
    RankOneTensor t1(5), t2(5);
    t1.loadData();
    t2.loadData();
    std::cout << "Values for RankOneTensor t1: " << t1 << std::endl
        << "Values for RankOneTensor t2: " << t2 << std::endl;

    RankOneTensor t3 = t1 + t2;
    std::cout << "RankOneTensor t3 (t1 + t2): " << t3 << std::endl;
}

// Test addition operator for RankTwoTensor
void testAddOperatorRankTwo() {
    RankTwoTensor t1(3, 3), t2(3, 3);
    t1.loadData();
    t2.loadData();
    std::cout << "Values for RankTwoTensor t1: " << t1 << std::endl
        << "Values for RankTwoTensor t2: " << t2 << std::endl;

    RankTwoTensor t3 = t1 + t2;
    std::cout << "RankTwoTensor t3 (t1 + t2): " << t3 << std::endl;
}

// Test assignment operator for RankOneTensor
void testAssignmentOperatorRankOne() {
    RankOneTensor t1(5), t2(5);
    t1.loadData();
       t2 = t1;
       std::cout << "Values for RankOneTensor t1: " << t1 << std::endl
           << "RankOneTensor t2 after assignment from t1: " << t2 << std::endl;
}

// Test assignment operator for RankTwoTensor
void testAssignmentOperatorRankTwo() {
    RankTwoTensor t1(3, 3), t2(3, 3);
    t1.loadData();
    t2 = t1;
    std::cout << "Values for RankTwoTensor t1: " << t1 << std::endl
        << "RankTwoTensor t2 after assignment from t1: " << t2 << std::endl;
}

// Test output stream operator for RankOneTensor
void testCoutStreamOperatorRankOne() {
    RankOneTensor t(5);
    t.loadData();

    std::cout << "RankOneTensor t: " << t << std::endl;
}

// Test output stream operator for RankTwoTensor
void testCoutStreamOperatorRankTwo() {
    RankTwoTensor t(3, 3);
    t.loadData();

    std::cout << "RankTwoTensor t: " << t << std::endl;
}

// Test input stream operator for RankOneTensor
void testCinStreamOperatorRankOne() {
    RankOneTensor t(1);
    std::cout << "Enter values for RankOneTensor (size 1): ";
    std::cin >> t;

    std::cout << "RankOneTensor t: " << t << std::endl;
}

// Test input stream operator for RankTwoTensor
void testCinStreamOperatorRankTwo() {
    RankTwoTensor t(1, 1);
    std::cout << "Enter values for RankTwoTensor (1x1): ";
    std::cin >> t;

    std::cout << "RankTwoTensor t: " << t << std::endl;
}

// Test index operator for RankOneTensor
void testIndexOperatorRankOne() {
    RankOneTensor t(5);
    t.loadData();

    std::cout << "RankOneTensor t: " << t << std::endl
        << "Element at t[2]: " << t[2] << std::endl;
}

// Test index operator for RankTwoTensor
void testIndexOperatorRankTwo() {
    RankTwoTensor t(3, 3);
    t.loadData();

    std::cout << "RankTwoTensor t: " << t << std::endl
        << "Element at t[0][1]: " << t[0][1] << std::endl;
}

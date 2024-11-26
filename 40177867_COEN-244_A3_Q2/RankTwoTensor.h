#pragma once
#include "BaseTensor.h"

#include<vector>
class RankTwoTensor :
    public BaseTensor
{
private: 
    
    std::vector<std::vector<double>> data; 

public: 

    // Constructors and destructor

    RankTwoTensor(int rows, int cols);
    RankTwoTensor(const RankTwoTensor& other);
    virtual ~RankTwoTensor() override;

    // Methodes

    virtual void loadData() override;

	RankTwoTensor operator++(); // prefix overload
	RankTwoTensor operator++(int); // postfix overload
	RankTwoTensor operator+(const RankTwoTensor&) const;	// add a tensor's values to another's
	RankTwoTensor operator+(double) const;	// adds a scalar element
	RankTwoTensor& operator=(const RankTwoTensor&);	// assigns the values of one tensor to another if the dimensions are the same
	double* operator[](int);	// checks index and retrieves value
	const double* operator[](int) const;	// checks index and retrieves value for const

	// Friend functions

	friend std::ostream& operator<<(std::ostream& output, const RankTwoTensor& tensor);	// outputs tensor's element values
	friend std::istream& operator>>(std::istream& input, RankTwoTensor& tensor);	// inputs tensor's element values
};


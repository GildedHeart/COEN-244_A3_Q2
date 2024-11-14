#pragma once
#include "BaseTensor.h"
#include <vector>
#include <stdexcept>

class RankOneTensor :
	protected BaseTensor
{
private:

	std::vector<double> data;

public:

	// Constructors and destructor

	RankOneTensor();
	RankOneTensor(int size); // dimension size
	RankOneTensor(const RankOneTensor& other);
	virtual ~RankOneTensor() override;

	// Methodes

	virtual void loadData() override;

	RankOneTensor operator++(); // prefix overload
	RankOneTensor operator++(int); // postfix overload
	RankOneTensor operator+(const RankOneTensor&) const;	// add a tensor's values to another's
	RankOneTensor operator+(double) const;	// adds a scalar element
	RankOneTensor& operator=(const RankOneTensor&);	// assigns the values of one tensor to another if the dimensions are the same
	double& operator[](int);	// checks index and retrieves value
	const double& operator[](int) const;	// checks index and retrieves value for const

	// Friend functions

	friend std::ostream& operator<<(std::ostream& output, const RankOneTensor& tensor);	// outputs tensor's element values
	friend std::istream& operator>>(std::istream& input, RankOneTensor& tensor);	// inputs tensor's element values
};


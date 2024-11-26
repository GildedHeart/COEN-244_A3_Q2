#include "RankOneTensor.h"

// Constructors and destructor

RankOneTensor::RankOneTensor() {
	data.resize(1);
}

RankOneTensor::RankOneTensor(int size) { data.resize(size); }

RankOneTensor::RankOneTensor(const RankOneTensor& other) : data(other.data) {}

RankOneTensor::~RankOneTensor() {}

// Methodes

void RankOneTensor::loadData() {
	for (size_t i = 0; i < data.size(); i++) {
		data[i] = valueGen();
	}
}

RankOneTensor RankOneTensor::operator++() {	// prefix overload
	for (auto& element : data) {
		++element;
	}
	return *this;
} 
RankOneTensor RankOneTensor::operator++(int) {	// postfix overload
	RankOneTensor temp = *this;
	for (auto& element : data) {
		++element;
	}
	return temp;
}

RankOneTensor RankOneTensor::operator+(const RankOneTensor& rightSide) const {	// add a tensor's values to another's
	if (data.size() != rightSide.data.size()) {
		throw std::invalid_argument("Tensors don't have the same dimentionality.");
	}

	RankOneTensor temp(*this);
	for (size_t i = 0; i < data.size(); i++) { 
			temp.data[i] = data[i] + rightSide.data[i]; 
	} 
	return temp;
}

RankOneTensor RankOneTensor::operator+(double scalar) const{	// adds a scalar element
	RankOneTensor temp(data.size());
	for (size_t i = 0; i < data.size(); i++) { 
		temp.data[i] = data[i] + scalar; }
	return temp;
}

RankOneTensor& RankOneTensor::operator=(const RankOneTensor& other) {	// assigns the values of one tensor to another if the dimensions are the same
	if (this->data.size() != other.data.size()) { 
		throw std::invalid_argument("Tensors don't have the same dimentionality.");
	}

	if (this != &other) { 
		data = other.data;
	}
	return *this;
}

double& RankOneTensor::operator[](int i){	// checks index and retrieves value
	if (i >= data.size()) {
	throw std::out_of_range("Value is out of range.");
	} 
	return data[i];
}

const double& RankOneTensor::operator[](int i) const{	// checks index and retrieves value for const
	if (i >= data.size()) {
		throw std::out_of_range("Value is out of range.");
	}
	return data[i];
}

// Friend functions

std::ostream& operator<<(std::ostream& output, const RankOneTensor& tensor) {	// outputs tensor's element values
	for (const auto& element : tensor.data) { 
		output << element << " "; 
	}
	return output;
}

std::istream& operator>>(std::istream& input, RankOneTensor& tensor) {	// inputs tensor's element values
	for (auto& element : tensor.data) {
		input >> element; 
	} 
	return input;
	std::cin.clear();
}
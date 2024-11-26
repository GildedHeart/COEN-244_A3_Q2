#include "RankTwoTensor.h"

// Constructors and destructor

RankTwoTensor::RankTwoTensor(int rows, int cols) {
	data.resize(rows);

	for (int i = 0; i < rows; i++) {
		data[i].resize(cols);
	}
}

RankTwoTensor::RankTwoTensor(const RankTwoTensor& other) : data(other.data){}

RankTwoTensor::~RankTwoTensor() {}

// Methodes

void RankTwoTensor::loadData() {
		for (size_t i = 0; i < data.size(); i++) {
			for (size_t j = 0; j < data[i].size(); j++) {
				data[i][j] = valueGen();
			}
		}
	}

RankTwoTensor RankTwoTensor::operator++() {	 // prefix overload
	for (auto& row : data) {
		for (auto& element : row) {
			++element;
		}
	}
	return *this;
}

RankTwoTensor RankTwoTensor::operator++(int) {	// postfix overload
	RankTwoTensor temp = *this;
	for (auto& row : data) {
		for (auto& element : row) {
			++element;
		}
	}
	return temp;
} 

RankTwoTensor RankTwoTensor::operator+(const RankTwoTensor& rightSide) const {	// add a tensor's values to another's
	if (data.size() != rightSide.data.size() || data[0].size() != rightSide.data[0].size()) {
		throw std::invalid_argument("Tensors don't have the same dimentionality.");
	}

	RankTwoTensor temp(*this);
	for (size_t i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[0].size(); j++) {
		temp.data[i][j] += rightSide.data[i][j];
		}
	}
	return temp;
}	

RankTwoTensor RankTwoTensor::operator+(double scalar) const {	// adds a scalar element
	RankTwoTensor temp(*this);
	for (std::vector<double>& row : temp.data) {
		for (auto& element : row) {
			element += scalar;
		}
	}
	return temp;
}	

RankTwoTensor& RankTwoTensor::operator=(const RankTwoTensor& other) {	// assigns the values of one tensor to another if the dimensions are the same
	if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
		throw std::invalid_argument("Tensors don't have the same dimentionality.");
	}

	if (this != &other) {
		data = other.data;
	}
	return *this;
}	

double* RankTwoTensor::operator[](int i) {	// checks index and retrieves value
	if (i < 0 || i>= data.size()) {
		throw std::out_of_range("Value is out of range.");
	}
	return data[i].data();
}	

const double* RankTwoTensor::operator[](int i) const {	// checks index and retrieves value for const
	if (i > 0 || i >= data.size()) {
		throw std::out_of_range("Value is out of range.");
	}
	return data[i].data();
}	

// Friend functions

std::ostream& operator<<(std::ostream& output, const RankTwoTensor& tensor) {	// outputs tensor's element values
	for (const auto& row : tensor.data) {
		for (const auto& element : row) {
			output << element << " ";
		}
	}
	return output;
}	
std::istream& operator>>(std::istream& input, RankTwoTensor& tensor) {	// inputs tensor's element values
	for (auto& row : tensor.data) {
		for (auto& element : row) {
			input >> element;
		}
	}
	return input;
	std::cin.clear();
}	
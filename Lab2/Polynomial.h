#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

template <class A>
class Polynomial {
private:
	int length;
	A* coefficients;
public:
	Polynomial(int L, A arr[]) {
		length = L + 1;
		coefficients = new A[L+1];
		for (int i = 0; i < L+1; i++)
		{
			coefficients[i] = arr[i];
		}
	}
	Polynomial() {
		length = 0;
		coefficients = new A[10];
	}
	A Evaluate(A input);
	Polynomial operator+(Polynomial<A> B);
};

template<class A>
A Polynomial<A>::Evaluate(A input)
{
	A inputaux, result = this->coefficients[0];
	for (int i = 1; i < this->length; i++)
	{
		inputaux = 1;
		for (int j = 0; j < i; j++)
		{
			inputaux *= input;
		}
		result += this->coefficients[i] * inputaux;
	}
	return result;
}

template<class A>
Polynomial<A> Polynomial<A>::operator+(Polynomial<A> B)
{
	if (this->length > B.length)
	{
		for (int i = 0; i < B.length; i++)
		{
			this->coefficients[i] += B.coefficients[i];
		}
		return *this;
	}
	else {
		for (int i = 0; i < this->length; i++)
		{
			B.coefficients[i] += this->coefficients[i];
		}
		return B;
	}
}


#endif

#include <iostream>
#include <sstream>

using namespace std;

struct complex_t {
	float real;
	float imag;
};

complex_t add( complex_t lhs, complex_t rhs ) {
	lhs.real += rhs.real;
	lhs.imag += rhs.imag;
	return lhs;
}

complex_t sub( complex_t lhs, complex_t rhs ) {
	lhs.real -= rhs.real;
	lhs.imag -= rhs.imag;
	return lhs;
}

complex_t mul( complex_t lhs, complex_t rhs ) {
	complex_t complexn;
	complexn.real = lhs.real * rhs.real - lhs.imag * rhs.imag;
	complexn.imag = lhs.imag * rhs.real + lhs.real * rhs.imag;
	return complexn;
}

complex_t div( complex_t lhs, complex_t rhs ) {
	complex_t complexn;
	complexn.real = ( lhs.real * rhs.real + lhs.imag * rhs.imag ) / ( rhs.real * rhs.real + rhs.imag * rhs.imag );
	complexn.imag = ( lhs.imag * rhs.real - lhs.real * rhs.imag ) / ( rhs.real * rhs.real + rhs.imag * rhs.imag );
	return complexn;
}

bool write( ostream &stream, complex_t &lhs ) {
	cout << "(" << lhs.real << ", " << lhs.imag << ")" << '\n';
	return true;
}

bool read( istream &stream, complex_t &complex ) {
	char znak;
	if ( ( stream >> znak ) && ( znak == '(' ) && 
		( stream >> complex.real ) && 
		( stream >> znak ) && ( znak == ',' ) && 
		( stream >> complex.imag ) && 
		( stream >> znak ) && ( znak == ')' ) ) {
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	complex_t lhs, rhs;
	string stroka;
	char op;
	bool res = true;
	getline(cin, stroka);
	istringstream stream(stroka);


	if ( ( read( stream, lhs ) ) && ( stream >> op ) && ( read( stream, rhs ) ) ) {
		if ( op == '+' ) {
			lhs = add( lhs, rhs );
		}
		else if ( op == '-' ) {
			lhs = sub( lhs, rhs );
		}
		else if ( op == '*' ) {
			lhs = mul( lhs, rhs );
		}
		else if ( op == '/' ) {
			if ( ( rhs.real != 0 ) && ( rhs.imag != 0 ) ) {
				lhs = div( lhs, rhs );
			}
			else {
				res = false;
			}
		}
		else {
			res = false;
		}
	}
	else {
		res = false;
	}

	if ( res == true ) {
		write( cout, lhs );
	}
	else {
		cout << "An error has occured while reading input data";
	}
	
    cin.get();
    return 0;
}

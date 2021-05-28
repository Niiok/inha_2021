#include "pocket_calcurator.h"

using namespace Calc;

TokenStream ts;
//std::vector<Token> tok;

int main()
{
	using namespace std;

	//try {
		double val = 0;
		while (cin)
		{
			Token t = ts.get();

			if (t.kind_ == 'q') break;
			if (t.kind_ == ';' || t.kind_ == '=')
				cout << "=" << val << '\n';
			else
				ts.putback(t);

			val = Expression();

			/*getchar();
			rewind(stdin);*/
		}
	//}

	//catch (exception& e) {
	//	cerr << e.what() << '\n';
	//	getchar();
	//	rewind(stdin);
	//	return 1;
	//}

	//catch (...) {
	//	cerr << "exception \n";
	//	getchar();
	//	rewind(stdin);
	//	return 2;	//}

}

Calc::Token::Token(char kind, double value) : kind_{ kind }, value_{ value } {};

Token Calc::TokenStream::get()
{
	if (full_)
	{
		full_ = false;
		return buffer_;
	}
	else
	{
		char ch;
		std::cin >> ch;
		switch (ch)
		{
		case ';':
		case '=':

		case 'q':

		case '(': case ')': case '+': case '-': case '*': case '/':
			return Token(ch, 0);

		case'.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':
		{
			std::cin.putback(ch);	//we need complete literal, not broken one
			double val;
			std::cin >> val;
			return Token{ '8',val };	// kind '8' reptresents literal
		}
		default:
			assert(0);	// bad token
		}
	}
}

void Calc::TokenStream::putback(Token t)
{
	assert(!full_);	// INVARIANT : buffer must be empty

	buffer_ = t;
	full_ = true;
}

double Calc::Expression()
{
	double left = Term();	// first token

	Token t = ts.get();	// second token

	while (true)
	{
		switch (t.kind_)
		{
		case '+':
			left += Term();	// third and more
			t = ts.get();	//fourth and more
			break;

		case '-':
			left -= Term();	//third and more
			t = ts.get();	//fourth and more
			break;

		default:
			ts.putback(t);	//return second(or other) token if grammer doesn't need it
			return left;
		}
	}
}

double Calc::Term()
{
	double left = Primary();

	Token t = ts.get();

	while (true)
	{
		switch (t.kind_)
		{
		case '*':
			left *= Primary();
			t = ts.get();
			break;

		case '/': {
			double d = Primary();
			assert(d != 0);
			left /= d;
			t = ts.get();
			} break;

		default:
			ts.putback(t);
			return left;
		}
	}
}

double Calc::Primary()
{
	Token t = ts.get();
	
	switch (t.kind_)
	{
	case '(': {
		double d = Expression();
		t = ts.get();
		assert(t.kind_ == ')');
		return d;
		} break;

	case '-':
	{
		std::cin.putback('-');	//we need complete literal, not broken one
		double val;
		std::cin >> val;
		return val;
	}

	case '8':
		return t.value_;

	default :
		assert(false);
	}
}
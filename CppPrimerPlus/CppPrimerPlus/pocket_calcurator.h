#ifndef ___CALCURATOR
#define ___CALCURATOR

//Analysis : set of requirements, specification
//Design : overall structure, which part, how to communicate
//Implementation : write code, debugging
//
// whats the problem to solve? : think in user's point of view
// break whole program into manageable  parts.
// build small, limited prototype to solve main problem
// start program from initial version rather than whole program at once

/*	parse tree

Expression:
	Term
	Expression "+" Term
	Expression "-" Term
Term:
	Primary
	Term "*" Primary
	Term "/" Primary
	Term "%" Primary
Primary:
	Number
	"(" Expression ")"
Number:
	floating-point-literal

*/

// all rights reserved by bjarne stroustrup.

#include <iostream>
#include <vector>
#include <assert.h>

namespace Calc {

	class Token {
	public:
		Token(char kind, double value);
		char kind_;
		double value_;

	};

	class TokenStream {

	public:
		Token get();
		void putback(Token t);

	private:
		bool full_{ false };
		Token buffer_{Token(0,0)};
	
	};

	//Token GetToken();
	double Expression();
	double Term();
	double Primary();


}


#endif
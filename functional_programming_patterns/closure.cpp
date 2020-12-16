#include <functional>
#include <iostream>

/**
 In functional programming, the most basic concept is closure

 The difference between the concepts of lambda expression and closure is
 sometimes confusing, since lambda expression and closure were talked about
 together all the time.

 Scott Meyers got a good explanation to this using analogues. “The distinction
 between a lambda and the corresponding closure is precisely equivalent to the
 distinction between a class and an instance of the class. A class exists only
 in source code; it doesn’t exist at runtime. What exists at runtime are objects
 of the class type. Closures are to lambdas as objects are to classes. This
 should not be a surprise, because each lambda expression causes a unique class
 to be generated (during compilation) and also causes an object of that class
 type–a closure–to be created (at runtime).”

 Function Object (Functor)
				Function object overload the operator(). It
could capture the values by making a copy of the variables to its member
variables. The shortcoming is that for each different function call, regardless
of how simple it is, we would have to implement a new class, whereas
implementing a lambda expression is faster.

 Functions Using Static Variables
				We don’t actually like to use static variables
in the function, unless it is extremely necessary, because it would confuse the
readers. In addition, if you have a lot of function calls, it is likely that we
have a lot of static variables which is more undesired.

 Is Function Object Closure?
				No. According to the definition of closure, “In
programming languages, a closure, also lexical closure or function closure, is a
technique for implementing lexically scoped name binding in a language with
first-class functions”. As C++ does not allow defining functions and objects
inside a function, function object does not (always) allow lexical scoping,
where with lexical scope, a name always refers to its (more or less) local
lexical environment. In our case, x in the closure has always to be mapped to
the x in the local scope. In a function object, the member variables are
different from the local variables outside the function object, even though they
might have the same name.

*/

int main() {
	int x = 0;
	auto closure = [&x]() {
		x += 1;
		std::cout << "The x is: " << x << std::endl;
	};

	// calling closure
	for (auto i = 0; i < 5; ++i) closure();

	return 0;
}

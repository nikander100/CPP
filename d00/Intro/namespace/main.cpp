#include <stdio.h>

int	gl_var = 1;
int	f(void) {return 2; }

namespace	Foo
{

	int	gl_var = 3;
	int	f(void) {return 4; }
}

namespace	Bar
{

	int	gl_var = 5;
	int	f(void) {return 6; }
}

namespace	Muf = Bar; //Namespace alliasaing

int		main(void)
{
	printf("gl_var:			[%d]\n", gl_var); //gl == global var
	printf("f()			[%d]\n\n", f());
	
	printf("Foo::gl_var:		[%d]\n", Foo::gl_var); //scope resolution opperator ::
	printf("Foo::f()		[%d]\n\n", Foo::f()); //first namespace

	printf("Bar::gl_var:		[%d]\n", Bar::gl_var); //second namespace
	printf("Bar::f()		[%d]\n\n", Bar::f());

	printf("Muf::gl_var:		[%d]\n", Muf::gl_var); // Muf == Bar namespace
	printf("Muf::f()		[%d]\n\n", Muf::f());

	printf("::gl_var:		[%d]\n", ::gl_var); // == as global namespace (empty namespace)
	printf("::f()			[%d]\n\n", ::f());

	return (0);
}
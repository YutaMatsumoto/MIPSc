/* Simple builtin declarations */
unsigned char unsigned_character_var;
unsigned short unsigned_short_var;
unsigned int  unsigned_integer_var;
unsigned long unsigned_long_var;
/* unsigned long long unsigned_long_long_var; */
char	character_var;
short   short_var;
int     integer;
long    long_var;
/* ISO C90 does not support long long */
/* long long long_long_var; */
float float_var;
double double_var;

/* declaration initialization */
int foo = 3;

/* struct */
// typedef struct Foo {
	// int foo;
// } Foo;
/* Foo struct_foo; */ /* Error in our parser but gcc -ansi -pedantic compiles this*/

/* array */
/*int array1[2];*/ /* Error in our parser but gcc compiles this*/
int array2[] = { 1,2,3 };

/* const variable */
const int const_var;


/* multiple declarations */
int i,j;
int k,l=10;

/* function call */
/* function(); */ /*Error for some reason*/

/* illegal type specifier */
// double double double_double_var, double_double_var2;

/* declaration with only declaration-specifiers */
// double double;

#ifndef DEBUGMACROS
#define DEBUGMACROS

#include "iostream"

#define DBGPRINT(var) std::cout << #var"=" << var << " ";
#define TOCOUT(txt) std::cout << txt;
#define ENDL std::cout << std::endl;
#define FLUSH std::cout << std::flush;
#define ENDLFLUSH std::cout << std::endl << std::flush;


#endif // DEBUGMACROS


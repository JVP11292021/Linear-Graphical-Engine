#ifndef _DEBUG_H_
#define _DEBUG_H_

#if defined(BUILD_MODE)
	#define disp(expr) 
	#define dbgloc(msg)  
	#define dbgline 
	#define dbgtrace(msg) 
#else
	#define disp(expr)  std::cerr << __FILE__ << ":" << __LINE__ << ":" << " ; " <<  #expr << " = " << (expr)  <<  std::endl
	#define dbgloc(msg)  std::cerr << __FILE__ << ":" << __LINE__ << ":" << msg 
	#define dbgline __FILE__ << ":" << __LINE__ << ":"
	#define dbgtrace(msg) std::cerr << __FILE__ << ":" << __LINE__ << ": TRACING " << msg << "\n";
#endif 


#endif
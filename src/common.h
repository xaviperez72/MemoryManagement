#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>

#define LOG_ON 1 


#define Log_Var_Name_Addr(x) if(LOG_ON)std::cout<<"**"<<(#x)<<"** :"<<x<<":Addr:”<<&x<<”:\n"
#define Print(msg) if(LOG_ON)std::cout<<msg<<"\n"


#endif // COMMON_H_
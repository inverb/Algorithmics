#include <string>
#include "functions.h"

int main()
{

	std::cout<<"SET_ARENA 1\n";
	std::cin>>S;
	while(true)
	{
		if(active[arena]==1)
		{
			CHANGE_ARENA();
			continue;
		}
		GET_CONS();
		GET_STATE();
		if(state = turns)
		{
			active[arena]=1;
			CHANGE_ARENA();
			continue;
		}
		
		
		
		CHANGE_ARENA();
		break;
	}





    //write(std::string komenda)   wrzuca do serwera komende
    //wait()                       pobiera z serwera wektor kolejnych lini w postaci wektora stringów
    

    return 0;
}


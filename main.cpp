#include "reservoir.h"
#include "reverseorder.h"

int main()
{
	get_east_storage("05/20/2018");  
	get_min_east();
	get_max_east();
	
	compare_basins("09/13/2018");
	compare_basins("01/08/2018");
	compare_basins("09/17/2018");
	
	reverse_order("05/29/2018", "06/02/2018");

	return 0;
}

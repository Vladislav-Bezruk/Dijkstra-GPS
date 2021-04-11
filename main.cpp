#include <stdio.h>

#include "structures.cpp"

#include "functions.cpp"

#include "input.cpp"

int main() {
	 
    for (int i = 0; i < g.size; i++) {
    	for (int j = 0; j < g.size; j++) {
    		g.value[i][j] = data[i][j];
		}
	}
	
	//.print();
	
	//printf("\n\n\n");
	
	PATH cond(4);
	
	cond.add(0);

	cond.add(2);
	cond.add(3);

	cond.add(5);
	
	cond.add(7);
		
	findWaysCond(g, cond);
	
    return 0;
}



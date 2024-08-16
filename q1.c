#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();	
    // function = -(xi.x2).-(x3.x4).-(x5.x6)
	// make 6 variables x0,x1,x2 (in that order)
	bdd x1 = bdd_new_var_last(bddm);
	bdd x2 = bdd_new_var_last(bddm);
	bdd x3 = bdd_new_var_last(bddm);

	bdd x4 = bdd_new_var_last(bddm);
	bdd x5 = bdd_new_var_last(bddm);
	bdd x6 = bdd_new_var_last(bddm);

	// compute y = (x0.x1)+x2\
	bdd f1  = bdd_nand (bddm,x1,x2);	
    bdd f2  = bdd_nand (bddm,x3,x4);	
    bdd f3  = bdd_nand (bddm,x5,x6);	
	//bdd y  = bdd_or (bddm,x2,a);	

    bdd f4  = bdd_and (bddm,f1,f2);
    bdd f5  = bdd_and (bddm,f4,f3);

	// compute z = (x0 + x2).(x1 + x2)
	// bdd b = bdd_or (bddm, x0,x2);
	// bdd c = bdd_or (bddm, x1,x2);
	// bdd z = bdd_and (bddm, b, c);

	

	printf("----------------------------------------------------\n");

	// print y
	bdd_print_bdd(bddm,f5,NULL, NULL,NULL, stdout);

	return(0);
}


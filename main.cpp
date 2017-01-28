#include <iostream>
#include "ssr.h"
using namespace std;

int main(){
	List l("/home/ticop/Masaüstü/tList/jobs.data" ,"/home/ticop/Masaüstü/tList/check.data");
	
        l.changeJob("Got to the Gym",0);
        l.getDatas();
}

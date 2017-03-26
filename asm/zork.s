.name "zork"
.comment "just a basic living prog"

l2:
	sti  	r1,	%:live,	%1 	// sti : 0b / CB : 68 / r1 : 01 / %:live : 00 0f / %1 :  00 01
	and 	r1,	%0,	r1 	// and : 06 / CB : 64 / r1 : 01 / %0 : 00 00 00 00 / r1 : 01 
live: 	live 	%1		   	// live : 01 / %1 : 00 00 00 01
	zjmp 	%:live			// zjmp : 09 / %:live : ff fb




// CB : 68 in hex to binary : 01 10 10 00 -> 01 : register / 10 : direct / 10 direct / 00 : no 4th arg
		//but sti is reg + idx / reg + idx / reg so 1 + 2 + 2
// CB : 64 in hex to binary : 01 10 01 00 -> 01 : register / 10 : direct / 01 : register / 00 ...

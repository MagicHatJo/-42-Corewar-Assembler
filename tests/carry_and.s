.name "carry"
.comment "test"

start:
	ld %:point,r7
	ld %0,r2
	ld %1,r3
loop:	
	st r7,:point
	add r7,r2,r7
	#ld %42,r8
	ldi %4095, %42, r65 
	ldi %4095, %42, r65 
	and r3, r3, r3
	and r2, r2, r2
	and r2, r2, r2
	zjmp %:loop
	live	%0
	live	%0
point:	

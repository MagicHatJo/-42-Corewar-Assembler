.name		"Reg Test"
.comment	"Reg Test"

		sti		r1,%:slive,%1
		sti		r1,%:alive,%1
		sti		r1,%:live,%1
		ld		%1,r4
		ld		%42,r6
		fork	%:sum
		st		r1,6
		live	%0
		fork	%:add
sub:	add		r4,r2,r2
slive:	live	%0
		st		r2,72
		and		r3,r3,r3
		zjmp	%:sub
add:	add		r4,r2,r2
alive:	live	%0
		st		r2,72
		and		r3,r3,r3
		zjmp	%:add
sum:	add		r4,r6,r6
live:	live	%0
		st		r6,72
		and		r3,r3,r3
		zjmp	%:sum
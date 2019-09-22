.name		"The Thief"
.comment	"All ur process r belong to us"

		st		r1,11
		st		r1,14
		live	%0
jump:	lfork	%2040
		live	%0
		and		r13,r13,r13
		zjmp	%:jump
	
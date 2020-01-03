.name		"Viral"
.comment	"Infectious"

	ld  	%318992386,r2		#
	ld  	%318992387,r3		#
	ld  	%318992388,r4		#
	ld  	%318992389,r5		#
	st		r1,19	#5
	st		r1,6	#5
	live	%0		#5
	fork	-5		#3
	live	%0		#5
	st		r2,19   #03 50 02 00 18    4
	st		r3,19   #03 50 03 00 18    4
	st		r4,19   #03 50 04 00 18    4
	st		r5,19   #03 50 05 00 18    4

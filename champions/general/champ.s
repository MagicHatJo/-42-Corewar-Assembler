.name           "Steven"
.comment        "fork live zjmp loop defensive"

		sti		r1,%:live,%1	#7
		ld		%16777216,r13	#01 00 00 00
		ld		%72615430,r14	#04 54 r6 r6
		ld		%101318646,r15	#r6 09 ff f3
		ld		%13,r3			#7 interval
		ld		%22,r2			#7 start
live:	live	%0				#5	0
		sti		r13,r2,%38		#8
		sti		r1,r2,%33		#8
		sti		r14,r2,%31		#8
		sti		r15,r2,%29		#8	|
		add		r3,r2,r2		#5	|
		ldi		%:fork,%-1,r5		#7
		add		r5,r3,r5		#5
		sti		r5,%:fork,%-1	#7
fork:	fork	%0
		and		r7,r7,r7		#5
		zjmp	%:live			#3	21
jump:	live	%0
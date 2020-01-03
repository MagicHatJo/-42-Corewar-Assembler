.name		"Hopper"
.comment	"Happiness is an lfork away"

		sti		r1,%:live1,%1
		sti		r1,%:wall,%1
		ld		%786432,r2		#00 0c 00 00
		ld		%-4,r3
		ld		%4,r5
		ld		%33490692,r8	#01 ff 07 04
		ld		%1409484551,r9	#54 03 07 07
		ld		%16777216,r10	#01 00 00 00
		ld		%746498,r11		#00 0b 64 02
		ld		%-32766972,r12	#fe 0c 04 04
		ld		%1409614852,r13	#54 05 04 04
		ld		%106169862,r14	#06 54 06 06
		ld		%101318635,r15	#06 09 ff eb
		sti		r1,%:live2,%1
		fork	%:live2
live1:	live	%42				#5
		st		r10,-501		#5
		st		r11,-502		#5
		st		r1,-510
		st		r12,-508			#5
		st		r13,-509		#5
		st		r14,-510		#5
		st		r15,-511		#5
		lfork	%-541			#3
		fork	%:live2
wall:	live	%42
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,-511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		st		r2,511
		and		r6,r6,r6
		zjmp	%:wall
live2:	live	%42
		st		r10,511
		st		r11,510
		st		r1,502
		st		r8,504
		st		r9,503
		st		r14,502
		st		r15,501
		fork	%480
		and		r6,r6,r6
		zjmp	%:live1			#3

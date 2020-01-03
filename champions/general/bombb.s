.name		"Test front bomb"
.comment	"spawn lfork wall forward"

		ld		%786432,r2
		ld		%-4,r3
live:	live	%-2
		sti		r2,%511,r7
		add		r3,r7,r7
		and		r6,r6,r6
		zjmp	%:live
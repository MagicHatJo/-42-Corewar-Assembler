.name		"Test back bomb"
.comment	"spawn lfork wall behind"

		ld		%786432,r2
		ld		%4,r5
live:	live	%-1
		sti		r2,%-511,r4
		add		r5,r4,r4
		and		r6,r6,r6
		zjmp	%:live
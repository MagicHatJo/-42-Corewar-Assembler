.name		"Imp"
.comment	"Impervious Imperial Impossible"

	st		r1,6
go:	live	%1
	and		r2,r2,r2
	zjmp	%:go

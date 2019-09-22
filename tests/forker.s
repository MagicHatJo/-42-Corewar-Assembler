.name "forker"
.comment "get forked"

start:
	live	%-1
	lfork	%0
	zjmp	%128
	lfork	%:start
step:
	zjmp	%128
	
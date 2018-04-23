.name     "all"
.comment   							"a program which does every instruction"
		
l2:	sti	r30,%:live,%1
	and	r1,%0,r1
live:	live	%1
	ld	%42, r6
	zjmp	%:l2

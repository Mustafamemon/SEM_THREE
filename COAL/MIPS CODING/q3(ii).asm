.data
	A: .byte 0
	B: .byte 2
	C: .byte 3
	X: .byte 4
	Y: .byte 5
.text
	main:
		lb $t0,A
		lb $t1,B
		lb $t2,C
		lb $t3,X
		lb $t4,Y
		
		l1:	
			add $t0,$t0,1		
			
			beq $t2,$t1,x_10
			add $t3,$t4,10
			j l
			x_10:
				add $t3,$t4,2
			l:
		blt $t0,$t1,l1	
			
		li $v0,1
		move $a0,$t3
	 	syscall
	 end:
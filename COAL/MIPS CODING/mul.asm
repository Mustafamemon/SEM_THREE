.data
	X1: .half 1:20
	X2: .half 2:20
.text
	main:
	 	addi $t0,$zero,0
	 	while:
	 		 beq $t0,40,exit
	 		lh $t1,X1($t0)
	 		lh $t2,X2($t0)
	 		sh $t1,X2($t0)
	 		sh $t2,X1($t0)
	 		addi $t0,$t0,2
	 	j while
	 	exit:
	 	
	 	addi $t0,$zero,0
	 	while1:
	 		beq $t0,40,exit1
	 		lh $t1,X1($t0)
			li $v0,1
	 		move $a0,$t1
	 		syscall
	 		addi $t0,$t0,2
	 	j while1
	 	exit1:
	 	
	
	
	
	end:
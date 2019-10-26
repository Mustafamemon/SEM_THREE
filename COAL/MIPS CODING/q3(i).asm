.data
	
.text
	main:
		
		li $s0,0xD4A4
		li $s1,0xA
		addi $sp,$sp,-12
		sw $s0,0($sp)
		sw $s1,4($sp)
		jal Divide_R
		li $v0,10
		syscall
	Divide_R:
		li $s2,0x5
		sw $ra,8($sp)
		lw $s0,0($sp)
		lw $s1,4($sp)
		div $s0,$s0,$s1
		ble $s0,$s2,exit1
		addi $sp,$sp,-12
		sw $s0,0($sp)
		sw $s1,4($sp)
		jal Divide_R
	exit1:
		lw $ra,8($sp)
		addi $sp,$sp,12
	jr $ra
	

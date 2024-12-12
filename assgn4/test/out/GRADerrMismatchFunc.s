# Global variable allocations:
.data

.text
	jal main
	li $v0, 10
	syscall
	# Function definition
func:
	# Setting up FP
	sw $fp, ($sp)
	move $fp, $sp
	addi $sp, $sp, -4

	# Saving registers
	sw $s0, ($sp)
	addi $sp, $sp, -4
	sw $s1, ($sp)
	addi $sp, $sp, -4
	sw $s2, ($sp)
	addi $sp, $sp, -4
	sw $s3, ($sp)
	addi $sp, $sp, -4
	sw $s4, ($sp)
	addi $sp, $sp, -4
	sw $s5, ($sp)
	addi $sp, $sp, -4
	sw $s6, ($sp)
	addi $sp, $sp, -4
	sw $s7, ($sp)
	addi $sp, $sp, -4

	# Variable expression
	lw $s0, 4($sp)
	# Saving return address
	sw $ra, ($sp)

	# Evaluating and storing arguments

	# Evaluating argument 0
	# Variable expression
	lw $s0, 4($sp)

	# Storing argument 0
	sw $s0, -4($sp)
	addi $sp, $sp, -8

	# Jump to callee

	# jal will correctly set $ra as well
	jal startoutput

	# Deallocating space for arguments
	addi $sp, $sp, 4

	# Resetting return address
	addi $sp, $sp, 4
	lw $ra, ($sp)

	# Move return value into another reg
	move $s1, $2
	# Integer expression
	li $s1, 0
	# Set return value
	move $v0, $s1
	# Jump to end of current function
	j endfunc
endfunc:

	# Reloading registers
	addi $sp, $sp, 4
	lw $s7, ($sp)
	addi $sp, $sp, 4
	lw $s6, ($sp)
	addi $sp, $sp, 4
	lw $s5, ($sp)
	addi $sp, $sp, 4
	lw $s4, ($sp)
	addi $sp, $sp, 4
	lw $s3, ($sp)
	addi $sp, $sp, 4
	lw $s2, ($sp)
	addi $sp, $sp, 4
	lw $s1, ($sp)
	addi $sp, $sp, 4
	lw $s0, ($sp)

	# Setting FP back to old value
	addi $sp, $sp, 4
	lw $fp, ($sp)

	# Return to caller
	jr $ra

	# Function definition
main:
	# Setting up FP
	sw $fp, ($sp)
	move $fp, $sp
	addi $sp, $sp, -4

	# Saving registers
	sw $s0, ($sp)
	addi $sp, $sp, -4
	sw $s1, ($sp)
	addi $sp, $sp, -4
	sw $s2, ($sp)
	addi $sp, $sp, -4
	sw $s3, ($sp)
	addi $sp, $sp, -4
	sw $s4, ($sp)
	addi $sp, $sp, -4
	sw $s5, ($sp)
	addi $sp, $sp, -4
	sw $s6, ($sp)
	addi $sp, $sp, -4
	sw $s7, ($sp)
	addi $sp, $sp, -4

	# Variable expression
	lw $s2, 4($sp)
	# Saving return address
	sw $ra, ($sp)

	# Evaluating and storing arguments

	# Evaluating argument 0
	# Variable expression
	lw $s0, 4($sp)

	# Storing argument 0
	sw $s0, -4($sp)
	addi $sp, $sp, -8

	# Jump to callee

	# jal will correctly set $ra as well
	jal func

	# Deallocating space for arguments
	addi $sp, $sp, 4

	# Resetting return address
	addi $sp, $sp, 4
	lw $ra, ($sp)

	# Move return value into another reg
	move $s1, $2
endmain:

	# Reloading registers
	addi $sp, $sp, 4
	lw $s7, ($sp)
	addi $sp, $sp, 4
	lw $s6, ($sp)
	addi $sp, $sp, 4
	lw $s5, ($sp)
	addi $sp, $sp, 4
	lw $s4, ($sp)
	addi $sp, $sp, 4
	lw $s3, ($sp)
	addi $sp, $sp, 4
	lw $s2, ($sp)
	addi $sp, $sp, 4
	lw $s1, ($sp)
	addi $sp, $sp, 4
	lw $s0, ($sp)

	# Setting FP back to old value
	addi $sp, $sp, 4
	lw $fp, ($sp)

	# Return to caller
	jr $ra


# output function
startoutput:
	# Put argument in the output register
	lw $a0, 4($sp)
	# print int is syscall 1
	li $v0, 1
	syscall
	# jump back to caller
	jr $ra

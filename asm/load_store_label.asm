.data
c1: .byte 0
i2: .word 2
c2: .byte 0
i1: .word 1
f1: .float 1.1
f2: .float
b1: .byte 1 'a' 123123123123


.text


# Initialization

	li $s1,1
	li $s2,2
	li $s3,3
	li $s4,4
	li $s5,5
	li $s6,6
	li $s7,7
			
# Directly Use the Label To Load/Store 

	lw $t1,i2
	sw $t1,i1
	
	lb $s1,c1
	sb $s2,c1

# Load Address Of Label to A Register First

	li $t1,0x00000001
	li $t1,0x100 # This does not work?
	
	# load label's address to register
	la $t7,c1
	
	# store the value in the register to the label's address
	sb $t1,($t7)

	# load the value in the label's address to the register
	lb $t2,($t7)

.data    
	black:	  .word 0x00000
	white:	  .word 0xF600AB
	red:      .word 0xa33141
	orange:   .word 0xff8500
	purple:   .word 0x6F2DE9
	green:	  .word 0x00ff00
.text

	j main
	
	screen: 
		addi $t0, $zero, 65536
		add $t1, $t0, $zero 
		lui $t1, 0x1004 
		jr $ra

	cor: 
		lw $s2, green
		lw $s3, purple
		lw $s4, white
		lw $s5, red
		lw $s6, black
		lw $s7, orange
		jr $ra
		
	seg10:
		li $v0, 32
		li $a0, 100
		syscall
		jr $ra
		
	seg100:
		li $v0, 32
		li $a0, 100
		syscall
		jr $ra
	
		
	grid:
		add $t0, $t1, $zero
		addi $t2, $zero, 0
		grid1: 
			sw $s2, ($t0) 
			addi $t0, $t0, 4
			addi $t2, $t2, 1 
			beq $t2, 127, exitgrid1
			j grid1
		exitgrid1:
		addi $t2, $zero, 0
		grid2: 
			sw $s2, ($t0) 
			addi $t0, $t0, 512
			addi $t2, $t2, 1 
			beq $t2, 127, exitgrid2
			j grid2
		exitgrid2:
		addi $t2, $zero, 0
		grid3: 
			sw $s2, ($t0) 
			subi $t0, $t0, 4 
			addi $t2, $t2, 1 
			beq $t2, 127, exitgrid3
			j grid3
		exitgrid3:
		addi $t2, $zero, 0
		grid4: 
			sw $s2, ($t0) 
			subi $t0, $t0, 512 
			addi $t2, $t2, 1 
			beq $t2, 127, exitgrid4
			j grid4
		exitgrid4:
		jr $ra
		
		
	movimento: #move o bot
		Dir:
		jal find
		addi $t5, $t3, 4
		lw $s1, ($t5)
		beq $s1, $s2, Baixo
		sw $s6, ($t3)
		addi $t3, $t3, 4
		sw $s5, ($t3)
		jal seg10
		b Dir
		
		Baixo:
		addi $t0, $zero, 0
		LBaixo:
		jal find
		addi $t5, $t3, 512
		lw $s1, ($t5)
		beq $s1, $s2, Cima
		sw $s6, ($t3)
		addi $t3, $t3, 512
		sw $s5, ($t3)
		jal seg10
		addi $t0, $t0, 1
		beq $t0, 10, Esq
		b LBaixo
		
		Esq:
		jal find
		subi $t5, $t3, 4
		lw $s1, ($t5)
		beq $s1, $s2, Baixo2
		sw $s6, ($t3)
		subi $t3, $t3, 4
		sw $s5, ($t3)
		jal seg10
		b Esq
		
		Baixo2:
		addi $t0, $zero, 0
		LBaixo2:
		jal find
		addi $t5, $t3, 512
		lw $s1, ($t5)
		beq $s1, $s2, Cima
		sw $s6, ($t3)
		addi $t3, $t3, 512
		sw $s5, ($t3)
		jal seg10
		addi $t0, $t0, 1
		beq $t0, 10, Dir
		b LBaixo2
		
		Cima:
		jal find
		subi $t5, $t3, 512
		lw $s1, ($t5)
		beq $s1, $s2, Esq
		sw $s6, ($t3)
		subi $t3, $t3, 512
		sw $s5, ($t3)
		jal seg10
		b Cima
		
		find:		
		subi $t2, $t3, 512 
		lw $s1, ($t2)
		beq $s1, $s4, FRosa
		addi $t2, $t3, 4 
		lw $s1, ($t2)
		beq $s1, $s4, FRosa
		addi $t2, $t3, 512
		lw $s1, ($t2)
		beq $s1, $s4, FRosa
		subi $t2, $t3, 4
		lw $s1, ($t2)
		beq $s1, $s4, FRosa
		jr $ra
		
	
	FRosa:
		sw $s6, ($t3)
		LRosa:
		add $t3, $t2, $zero
		sw $s5, ($t3)
		jal seg100
		subi $t2, $t3, 512 
		lw $s1, ($t2)
		beq $s1, $s4, Corange
		addi $t2, $t3, 4 
		lw $s1, ($t2)
		beq $s1, $s4, Corange
		addi $t2, $t3, 512 
		lw $s1, ($t2)
		beq $s1, $s4, Corange
		subi $t2, $t3, 4 
		lw $s1, ($t2)
		beq $s1, $s4, Corange
		b Forange
		Corange:
		sw $s7, ($t3)
		b LRosa
		
	Forange: 
		subi $t2, $t3, 512 
		lw $s1, ($t2)
		beq $s1, $s7, Cpurple
		beq $s1, $s4, FRosa2
		addi $t2, $t3, 4 
		lw $s1, ($t2)
		beq $s1, $s7, Cpurple
		beq $s1, $s4, FRosa2
		addi $t2, $t3, 512 
		lw $s1, ($t2)
		beq $s1, $s7, Cpurple
		beq $s1, $s4, FRosa2
		subi $t2, $t3, 4
		lw $s1, ($t2)
		beq $s1, $s7, Cpurple
		beq $s1, $s4, FRosa2
		exitForange:
		j exitMain
		Cpurple:
		sw $s3, ($t3)
		add $t3, $t2, $zero
		sw $s5, ($t3)
		jal seg100
		b Forange
			
	FRosa2:
		sw $s3, ($t3)
		LRosa2:
		add $t3, $t2, $zero
		sw $s5, ($t3)
		jal seg100
		subi $t2, $t3, 512 
		lw $s1, ($t2)
		beq $s1, $s4, Cpurple2
		addi $t2, $t3, 4 
		lw $s1, ($t2)
		beq $s1, $s4, Cpurple2
		addi $t2, $t3, 512 
		lw $s1, ($t2)
		beq $s1, $s4, Cpurple2
		subi $t2, $t3, 4 
		lw $s1, ($t2)
		beq $s1, $s4, Cpurple2
		jr $ra
		Cpurple2:
		sw $s3, ($t3)
		b LRosa2			
	
		
	randBot:
		add $a1, $t8, $zero
		li $v0, 42
		syscall
		addi $s0, $a0, 1
		add $a1, $t9, $zero
		li $v0, 42
		syscall
		addi $t5, $a0, 1
		li $t6, 128
		mul $t5, $t5, $t6
		add $s0, $s0, $t5	
		add $s0, $s0, $s0
		add $t7, $s0, $s0
		jr $ra
		
	
	
	u: 
		add $t0, $zero, $t3
		addi $t2, $zero, 0
		lu1:
			sw $s4, ($t0)
			addi $t0, $t0, 512 
			addi $t2, $t2, 1
			beq $t2, 39, exitu1
			j lu1
		exitu1:
		addi $t2, $zero, 0
		lu2:
			sw $s4, ($t0) 
			addi $t0, $t0, 4 
			addi $t2, $t2, 1 
			beq $t2, 29, exitu2
			j lu2
		exitu2:
		addi $t2, $zero, 0
		lu3:
			sw $s4, ($t0)
			addi $t0, $t0, -512 
			addi $t2, $t2, 1
			beq $t2, 40, exitu3
			j lu3
		exitu3:
	
		jr $ra
	
	
	espiral:
		add $t0, $zero, $t3
		addi $t2, $zero, 0
		e1:
			sw $s4, ($t0)
			addi $t0, $t0, 512 
			addi $t2, $t2, 1
			beq $t2, 39, exite1
			j e1
		exite1:	
		addi $t2, $zero, 0
		e2:
			sw $s4, ($t0) 
			addi $t0, $t0, 4 
			addi $t2, $t2, 1 
			beq $t2, 30, exite2
			j e2
		exite2:
		addi $t2, $zero, 0
		e3:
			sw $s4, ($t0)
			addi $t0, $t0, -512 
			addi $t2, $t2, 1
			beq $t2, 34, exite3
			j e3
		exite3:
		addi $t2, $zero, 0
		e4:
			sw $s4, ($t0)
			addi $t0, $t0, -4 
			addi $t2, $t2, 1
			beq $t2, 26, exite4
			j e4
		exite4:
		addi $t2, $zero, 0
		e5:
			sw $s4, ($t0)
			addi $t0, $t0, 512 
			addi $t2, $t2, 1
			beq $t2, 29, exite5
			j e5
		exite5:	
		addi $t2, $zero, 0
		e6:
			sw $s4, ($t0) 
			addi $t0, $t0, 4 
			addi $t2, $t2, 1 
			beq $t2, 22, exite6
			j e6
		exite6:		
		addi $t2, $zero, 0
		e7:
			sw $s4, ($t0) 
			addi $t0, $t0, -512
			addi $t2, $t2, 1
			beq $t2, 20, exite7
			j e7
		exite7:			
		jr $ra
	
main:
	jal screen
	jal cor
	jal grid
	
	li $a1, 3
	li $v0, 42
	syscall
	beq $a0, 1, setU
	beq $a0, 0, setEsp
	setU:
	li $t8, 98
	li $t9, 88
	jal randBot
	add $t3, $t1, $t7
	jal u
	b ponto
	setEsp:
	li $t8, 98
	li $t9, 88
	jal randBot
	add $t3, $t1, $t7
	jal espiral
	ponto:
	li $t8, 126
	li $t9, 126
	jal randBot
	add $t3, $t1, $t7
	j movimento
	exitMain:
	jal Forange
	li $v0, 10
	syscall

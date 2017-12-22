IIADDQ
ALUADD

phase			iaddq V rB

fetch			icode:ifun <- M1[PC}
			rA:rB <- M1[PC+1]
			valC  <- M8[PC+2]
			valP  <- PC + 10
#############################################
decode
			valB <- R[rb]
#############################################
execute			valE <- valB add valC
			set CC
#############################################
memory
#############################################
write back		R[rB] <- valE
#############################################
PC			PC <- valP


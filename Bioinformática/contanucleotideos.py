'''Lê um arquivo FASTA e retorna 4 números inteiros (separados por espaço) contando o respectivo número de vezes 
que os símbolos 'A', 'C', 'G', e 'T' aparecem'''

#!/usr/bin/env python
# coding: utf-8

from Bio import SeqIO

A=0; C=0; G=0; T=0

for record in SeqIO.parse("genomacovid.fasta", "fasta"):
    
    for c in record.seq:
        if c == 'A':
            A+=1
        if c == 'C':
            C+=1
        if c == 'G':
            G+=1
        if c == 'T':
            T+=1
    
print("A:",A, "C:", C, "G:", G, "T:", T)

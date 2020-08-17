'''Realiza a transcrição do DNA contido em um arquivo FASTA e cria um arquivo FASTA contendo o DNA transcrito e sua descrição.'''

#!/usr/bin/env python
# coding: utf-8

from Bio import SeqIO

rna = ""

for record in SeqIO.parse("genomacovid.fasta", "fasta"):
    for c in record.seq:
        if c == "T":
            rna+="U"
        else:
            rna+=c
            
arquivo = open("transccovid.fasta", "w")

arquivo.write(">" + record.description + "\n" + rna)

arquivo.close()

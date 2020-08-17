'''Programa que lê um arquivo FASTA e realiza a transcrição do DNA contido no mesmo, armazenando o DNA transcrito em um novo arquivo.'''

#!/usr/bin/env python
# coding: utf-8

from Bio import SeqIO
from Bio import Seq

#para realizar a transcrição de outros genomas, mudar o nome "genomacovid.fasta" para o nome de seu arquivo
for record in SeqIO.parse("genomacovid.fasta", "fasta"):
    record.seq = Seq.transcribe(record.seq)    

#para mudar o nome do arquivo criado, alterar "transccovid.fasta" para o nome desejado
SeqIO.write(record, "transccovid.fasta", "fasta")

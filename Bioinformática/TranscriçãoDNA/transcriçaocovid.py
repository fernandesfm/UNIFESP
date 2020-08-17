#!/usr/bin/env python
# coding: utf-8

from Bio import SeqIO
from Bio import Seq

for record in SeqIO.parse("genomacovid.fasta", "fasta"):
    record.seq = Seq.transcribe(record.seq)    

SeqIO.write(record, "transccovid.fasta", "fasta")
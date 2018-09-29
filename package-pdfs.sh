#!/bin/bash
problem2pdf beautifulprimes
problem2pdf chocolates 
problem2pdf enigma 
problem2pdf limbo1 
problem2pdf limbo2 
problem2pdf mayhem 
problem2pdf piperotation 
problem2pdf polarexpress 
problem2pdf thanos 
problem2pdf wiseguy 
echo "joining problem statements"
# have to have poppler utils installed
pdfunite utscode-cover/utscode-cover.pdf  beautifulprimes.pdf chocolates.pdf enigma.pdf limbo1.pdf limbo2.pdf mayhem.pdf piperotation.pdf polarexpress.pdf thanos.pdf wiseguy.pdf problemset.pdf

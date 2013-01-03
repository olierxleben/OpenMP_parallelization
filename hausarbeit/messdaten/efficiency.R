#!/usr/bin/Rscript

source(file="output.R")

inp <- read.csv("intel-benchmark-13.csv", sep=";")
out.filename <- "s13_efficiency"

aggr <- aggregate(inp$Walltime, by=list(inp$Implementierung, inp$Threads), FUN=median)

names(aggr)[1] <- "Implementierung"
names(aggr)[2] <- "Threads"
names(aggr)[3] <- "Walltime"

omp <- aggr[aggr$Implementierung=="OMP",]
tbb <- aggr[aggr$Implementierung=="TBB",]

omp_rseq <- max(omp$Walltime)
tbb_rseq <- max(tbb$Walltime)

cat("Sequential runtime (OMP):", omp_rseq, "\n")
cat("Sequential runtime (TBB):", tbb_rseq, "\n")

setOutput()

plot(omp$Threads, (omp_rseq/omp$Walltime)/omp$Threads, col="red", ylim=c(0, 1.2), xlab="Threads", ylab="Effizienz", lwd=out.lwd)
points(tbb$Threads, (tbb_rseq/tbb$Walltime)/tbb$Threads, col="blue", pch=2, lwd=out.lwd)

omp_ideal <- function(x) 0*x + 1
curve(omp_ideal, add=TRUE, col="green", lty=2, lwd=out.lwd)

legend(x="topright", legend=c("OMP","TBB","Ideal"), col=c("red","blue","green"), pch=c(1,2,-1), lty=c(-1,-1,2), bg="white", lwd=out.lwd)

resetOutput();

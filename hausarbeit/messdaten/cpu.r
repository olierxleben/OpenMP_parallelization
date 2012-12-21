#!/usr/bin/R

library(ggplot2)

inp <- read.csv("intel-benchmark-13.csv", sep=";")

aggr <- aggregate(inp$Cpu, by=list(inp$Implementierung, inp$Threads), FUN=mean)

names(aggr)[1] <- "Implementierung"
names(aggr)[2] <- "Threads"
names(aggr)[3] <- "Cpu"

omp <- aggr[aggr$Implementierung=="OMP",]
tbb <- aggr[aggr$Implementierung=="TBB",]

omp_rseq <- max(omp$Walltime)
tbb_rseq <- max(tbb$Walltime)

png("s13_cpu.png", width=1024, height=768, pointsize=24)
#pdf("s13_cpu.pdf")

plot(omp$Threads, omp$Cpu, col="red", ylim=c(0, 24), xlab="Threads", ylab="CPU-Auslastung")
points(tbb$Threads, tbb$Cpu, col="blue")

omp_ideal <- function(x) x
curve(omp_ideal, add=TRUE, col="green", lty=2)

title("Szenario 13, CPU-Auslastung")
legend(x="topright", legend=c("OMP","TBB","Ideal"), col=c("red","blue","green"), pch=c(1,1,-1), lty=c(-1,-1,2), bg="white")

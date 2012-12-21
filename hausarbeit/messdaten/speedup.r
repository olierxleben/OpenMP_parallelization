#!/usr/bin/R

library(ggplot2)

inp <- read.csv("intel-benchmark-13.csv", sep=";")

aggr <- aggregate(inp$Walltime, by=list(inp$Implementierung, inp$Threads), FUN=median)

names(aggr)[1] <- "Implementierung"
names(aggr)[2] <- "Threads"
names(aggr)[3] <- "Walltime"

omp <- aggr[aggr$Implementierung=="OMP",]
tbb <- aggr[aggr$Implementierung=="TBB",]

omp_rseq <- max(omp$Walltime)
tbb_rseq <- max(tbb$Walltime)

png("s13_speedup.png", width=1024, height=768, pointsize=24)
#pdf("s13_speedup.pdf")

plot(omp$Threads, omp_rseq/omp$Walltime, col="red", ylim=c(1, 24), xlab="Threads", ylab="Speed-Up", log="y")
points(tbb$Threads, tbb_rseq/tbb$Walltime, col="blue")

omp_ideal <- function(x) x
curve(omp_ideal, add=TRUE, col="green", lty=2)

title("Szenario 13, Speed-Up")
legend(x="topright", legend=c("OMP","TBB","Ideal"), col=c("red","blue","green"), pch=c(1,1,-1), lty=c(-1,-1,2), bg="white")

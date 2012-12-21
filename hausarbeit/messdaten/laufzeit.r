#!/usr/bin/R

library(ggplot2)

inp <- read.csv("intel-benchmark-13.csv", sep=";")

aggr <- aggregate(inp$Walltime, by=list(inp$Implementierung, inp$Threads), FUN=mean)

names(aggr)[1] <- "Implementierung"
names(aggr)[2] <- "Threads"
names(aggr)[3] <- "Walltime"

omp <- aggr[aggr$Implementierung=="OMP",]
tbb <- aggr[aggr$Implementierung=="TBB",]

omp_ideal <- function(x) max(omp$Walltime) / x
tbb_ideal <- function(x) max(tbb$Walltime) / x

png("s13_runtime.png", width=1024, height=768, pointsize=24)
#pdf("s13_runtime.pdf")

plot(omp$Threads, omp$Walltime, col="red", ylim=c(0, max(aggr$Walltime)*1.1), xlab="Threads", ylab="Laufzeit (Sekunden)")
points(tbb$Threads, tbb$Walltime, col="blue")

curve(omp_ideal, add=TRUE, col="green", lty=2)

title("Szenario 13, Laufzeit")
legend(x="topright", legend=c("OMP","TBB","Ideal"), col=c("red","blue","green"), pch=c(1,1,-1), lty=c(-1,-1,2))

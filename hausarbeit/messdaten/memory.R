#!/usr/bin/Rscript

source(file="output.R")

inp <- read.csv("intel-benchmark-mem.csv", sep=";")
out.filename <- "s14_memory"

inp$Speicher <- inp$Speicher / (1024 * 1024)

aggr <- aggregate(inp$Speicher, by=list(inp$Implementierung, inp$Threads), FUN=median)

names(aggr)[1] <- "Implementierung"
names(aggr)[2] <- "Threads"
names(aggr)[3] <- "Speicher"

omp <- aggr[aggr$Implementierung=="OMP",]
tbb <- aggr[aggr$Implementierung=="TBB",]

setOutput()

print(omp)

plot(omp$Threads, omp$Speicher, col="red", ylim=c(min(inp$Speicher)*0.99, max(inp$Speicher)*1.01), xlab="Threads", ylab="Speicher (MiB)", xaxt="n", lwd=out.lwd)
points(tbb$Threads, tbb$Speicher, col="blue", pch=2, lwd=out.lwd)

axis(1, at=c(1,1:6*4))

legend(x="topright", legend=c("OMP","TBB"), col=c("red","blue"), pch=c(1,2), lty=c(-1,-1), bg="white", lwd=out.lwd)

resetOutput()

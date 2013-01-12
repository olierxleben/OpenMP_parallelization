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

omp_mean <- median(omp$Speicher)
tbb_mean <- median(tbb$Speicher)

setOutput()

print(omp)

plot(omp$Threads, omp$Speicher, col="red", ylim=c(min(inp$Speicher)*0.99, max(inp$Speicher)*1.01), xlab="Threads", ylab="Speicher (MiB)", xaxt="n", lwd=out.lwd)
points(tbb$Threads, tbb$Speicher, col="blue", pch=2, lwd=out.lwd)

curve(omp_mean + 0*x, col="red", add=TRUE, lty=2)
curve(tbb_mean + 0*x, col="blue", add=TRUE, lty=2)

axis(1, at=c(1,1:6*4))

legend(x="topright", legend=c("OMP","TBB"), col=c("red","blue"), pch=c(1,2), lty=c(-1,-1), bg="white", lwd=out.lwd)

text(labels=c(paste(c("OMP: ",round(omp_mean,3)," MiB"),collapse='')), x=21, y=omp_mean*1.002)
text(labels=c(paste(c("TBB: ",round(tbb_mean,3)," MiB"),collapse='')), x=21, y=tbb_mean*0.998)

cat((1 - min(tbb_mean,omp_mean)/max(tbb_mean,omp_mean)) * 100, "% schneller\n")

resetOutput()

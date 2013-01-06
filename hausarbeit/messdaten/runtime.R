#!/usr/bin/Rscript

source(file="output.R")

inp <- read.csv("intel-benchmark-13.csv", sep=";")
out.filename <- "s13_runtime"

aggr <- aggregate(inp$Walltime, by=list(inp$Implementierung, inp$Threads), FUN=mean)

names(aggr)[1] <- "Implementierung"
names(aggr)[2] <- "Threads"
names(aggr)[3] <- "Walltime"

omp <- aggr[aggr$Implementierung=="OMP",]
tbb <- aggr[aggr$Implementierung=="TBB",]

all_ideal <- function(x) mean(c(max(omp$Walltime),max(tbb$Walltime))) / x

cat("Ideal runtimes (Mean):", mean(c(max(omp$Walltime),max(tbb$Walltime))), "/ p\n")

omp_conv <- mean(omp[omp$Threads>=12,]$Walltime)
tbb_conv <- mean(tbb[tbb$Threads>=12,]$Walltime)

cat("Convergence (OMP):", omp_conv, "seconds\n")
cat("Convergence (TBB):", tbb_conv, "seconds\n")

setOutput()

plot(omp$Threads, omp$Walltime, col="red", ylim=c(0, max(aggr$Walltime)*1.1), xlab="Threads", ylab="Laufzeit (Sekunden)", lwd=out.lwd, xaxt="n")
points(tbb$Threads, tbb$Walltime, col="blue", pch=2, lwd=out.lwd)

curve(all_ideal, add=TRUE, col="green", lty=2, lwd=out.lwd)
curve(0*x + omp_conv, add=TRUE, col="red", lty=3)
curve(0*x + tbb_conv, add=TRUE, col="blue", lty=3)

axis(1, at=c(1,1:6*4))
legend(x="topright", legend=c("OMP","TBB","Ideal"), col=c("red","blue","green"), pch=c(1,2,-1), lty=c(-1,-1,2), lwd=out.lwd)

text(labels=c(paste(c("OMP: ",round(omp_conv,3),"s"),collapse='')), x=20, y=omp_conv*0.8)
text(labels=c(paste(c("TBB: ",round(tbb_conv,3),"s"),collapse='')), x=20, y=tbb_conv*1.2)

resetOutput()

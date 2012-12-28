#!/usr/bin/R

source(file="output.R")

inp <- read.csv("intel-benchmark-13.csv", sep=";")
out.filename <- "s13_runtime"

aggr <- aggregate(inp$Walltime, by=list(inp$Implementierung, inp$Threads), FUN=mean)

names(aggr)[1] <- "Implementierung"
names(aggr)[2] <- "Threads"
names(aggr)[3] <- "Walltime"

omp <- aggr[aggr$Implementierung=="OMP",]
tbb <- aggr[aggr$Implementierung=="TBB",]

omp_ideal <- function(x) max(omp$Walltime) / x
tbb_ideal <- function(x) max(tbb$Walltime) / x

omp_conv <- mean(omp[omp$Threads>=12,]$Walltime)
tbb_conv <- mean(tbb[tbb$Threads>=12,]$Walltime)

#png("s13_runtime.png", width=1024, height=768, pointsize=24)
pdf(paste(c(out.filename,".pdf"),collapse=''), width=pdf.width, height=pdf.height, pointsize=pdf.pointsize, family=CM)
par(mar=c(4,4,1,1)+0.1)

plot(omp$Threads, omp$Walltime, col="red", ylim=c(0, max(aggr$Walltime)*1.1), xlab="Threads", ylab="Laufzeit (Sekunden)")
points(tbb$Threads, tbb$Walltime, col="blue", pch=2)

curve(omp_ideal, add=TRUE, col="green", lty=2)
curve(0*x + omp_conv, add=TRUE, col="red", lty=3)
curve(0*x + tbb_conv, add=TRUE, col="blue", lty=3)

#title("Szenario 13, Laufzeit")
legend(x="topright", legend=c("OMP","TBB","Ideal"), col=c("red","blue","green"), pch=c(1,2,-1), lty=c(-1,-1,2))

text(labels=c(paste(c("OMP: ",round(omp_conv,3),"s"),collapse='')), x=20, y=omp_conv*0.8)
text(labels=c(paste(c("TBB: ",round(tbb_conv,3),"s"),collapse='')), x=20, y=tbb_conv*1.2)

dev.off()
embedFonts(paste(c(out.filename,".pdf"),collapse=''), fontpaths=c("cm-lgc/fonts/type1/public/cm-lgc/", "."))

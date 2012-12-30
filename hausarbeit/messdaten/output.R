
CM <- Type1Font("CM",
                c("cm-lgc/fonts/afm/public/cm-lgc/fcmr8a.afm",
                  "cm-lgc/fonts/afm/public/cm-lgc/fcmb8a.afm",
                  "cm-lgc/fonts/afm/public/cm-lgc/fcmri8a.afm",
                  "cm-lgc/fonts/afm/public/cm-lgc/fcmbi8a.afm")) 

pdf.width <- 5
pdf.height <- 3.5
pdf.pointsize <- 8

png.width <- 1024
png.height <- 768
png.pointsize <- 24

out.mode <- commandArgs(trailingOnly=TRUE)[1]
cat("Output mode:", out.mode, "\n")

if (is.na(out.mode)) {
	stop("Missing output mode.")
} else if (out.mode != "png" && out.mode != "pdf") {
	stop("Unknown output mode:", out.mode)
}

setOutput <- function() {
	if (out.mode == "png") {
		cat("Setting PNG output.\n")
		png(paste(c(out.filename,".png"),collapse=''), width=png.width, height=png.height, pointsize=png.pointsize)
	} else {
		cat("Setting PDF output.\n")
		pdf(paste(c(out.filename,".pdf"),collapse=''), width=pdf.width, height=pdf.height, pointsize=pdf.pointsize, family=CM)
	}
	par(mar=c(4,4,1,1)+0.1)
}

resetOutput <- function() {
	dev.off()

	if (out.mode == "pdf") {
		cat("Embedding fonts into pdf...")
		embedFonts(paste(c(out.filename,".pdf"),collapse=''), fontpaths=c("cm-lgc/fonts/type1/public/cm-lgc/", "."))
		cat("Done.\n")
	}

	cat("Done.\n")
}

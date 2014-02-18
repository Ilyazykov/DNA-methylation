setwd("C:/Users/user/Desktop/Diploma/DNA-methylation/DNAmethylation/CourseWork")

mydata <- read.table("efficiencies.txt", dec=".")
attach(mydata)
v1 <- mydata$V1
v2 <- mydata$V2
load("phenDataTCGABRCA.rd")

control1 <- v1[which(phen==FALSE)] 
control2 <- v2[which(phen==FALSE)] 

control1 = control1[(length(control1) / 2):(length(control1))]
control2 = control2[(length(control2) / 2):(length(control2))]

case1 <- v1[which(phen==TRUE)]
case2 <- v2[which(phen==TRUE)]

min1 = min(control1,case1)
max1 = max(control1,case1)

min2 = min(control2,case2)
max2 = max(control2,case2)

plot(0,0, xlim=c(min1,max1), ylim=c(min2,max2))
points(case1, case2, col="red")
points(control1, control2, col="blue")
dev.copy2pdf(file=paste("plot.pdf",sep=""))


//-------------------------------------------------
library(e1071)
library(rpart)
svm.TP = svm.FN = svm.FP = svm.TN = 0
for (i in 1:n){
	svm.model <- svm(datafile[-i,1]~.,datafile[-i,2:9])
	pred <- predict(svm.model, datafile[i,2:9])
	if (pred >= 0.5) {
		pred = 1
	} else {
		pred = 0
	}

	if (pred == datafile[i,1]) {
		if (pred == 1) {
		svm.TP = svm.TP+1
		} else {
			svm.TN = svm.TN+1
		}
	} else {
		if (pred == 1) {
		svm.FP = svm.FP+1
		} else {
			svm.FN = svm.FN+1
		}
	}
}

svm.sensitivity = svm.TP/(svm.TP+svm.FN)
svm.specificity = svm.TN/(svm.TN+svm.FP)
svm.accuracy = (svm.TP+svm.TN)/(svm.TP+svm.TN+svm.FP+svm.FN)
svm.precision = svm.TP/(svm.TP+svm.FP)

sink("c:/output.txt")

svm.TP
svm.FN
svm.FP
svm.TN
svm.sensitivity
svm.specificity
svm.accuracy
svm.precision

sink()
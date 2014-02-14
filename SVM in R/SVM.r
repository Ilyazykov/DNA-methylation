mydata <- read.xls("C:/data.xls")

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
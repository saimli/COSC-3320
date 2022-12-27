
#0
attach(Processed_Marriage_Divorce_DB)
install.packages("dplyr")
library(dplyr)  

#1
dataa <- data.frame(Age.Gap,
                    Economic.Similarity,
                    Common.Interests,
                    Divorce.Score)
cov(dataa)

covvy
cor(covvy)
cor(dataa)

cov(Age.Gap,Economic.Similarity)
cov(Common.Interests,Divorce.Score)


#2
data2<-data.frame(Common.Interests,Love)
plot(data2)
abline(data2,col="red")

#3
#filtered db for marry and divorce recommendations
dataDIVORCE<-filter(Processed_Marriage_Divorce_DB, Recommendation=="Divorce")
dataMARRY<-filter(Processed_Marriage_Divorce_DB, Recommendation=="Marry")
#creating histograms
hist(dataMARRY$Divorce.Score)
hist(dataDIVORCE$Divorce.Score)
hist(dataMARRY$Desire.to.Marry)
hist(dataDIVORCE$Desire.to.Marry)
hist(dataMARRY$Common.Interests)
hist(dataDIVORCE$Common.Interests)


#4
boxplot()
median(Self.Confidence)
boxplot(Self.Confidence)
boxplot(dataMARRY$Self.Confidence)
median(dataMARRY$Self.Confidence)
boxplot(dataDIVORCE$Self.Confidence)
median(dataDIVORCE$Self.Confidence)



#5

plot(density(Common.Interests),xlim=c(-20,150),ylim=c(-0,.025),lwd=2.0,col=2)
lines(density(Economic.Similarity),col=1,lwd=2.0)
legend("topright",c("Economic Similarity","Common Interests"),col=1:2,lty=1,lwd=3.0)

plot(density(Common.Interests),xlim=c(-20,150),ylim=c(-0,.025),lwd=2.0,col=2)
lines(density(Loyalty),col=1,lwd=2.0)
legend("topright",c("Loyalty","Common Interests"),col=1:2,lty=1,lwd=3.0)

plot(density(Economic.Similarity),xlim=c(-20,150),ylim=c(-0,.025),lwd=2.0,col=2)
lines(density(Loyalty),col=1,lwd=2.0)
legend("topright",c("Loyalty","Economic Similarity"),col=1:2,lty=1,lwd=3.0)


#6
plot(density(Age.Gap),lwd=3.0,col=2)
plot(density(Social.Gap),lwd=3.0,col=2)

plot(density(dataMARRY$Age.Gap),lwd=3.0,col=2)
lines(density(dataDIVORCE$Age.Gap),lwd=3.0,col=1)
legend("topright",c("Divorce","Marry"),col=1:2,lty=1,lwd=3.0)


plot(density(dataMARRY$Social.Gap),ylim=c(0,.013),lwd=3.0,col=2)
lines(density(dataDIVORCE$Social.Gap),lwd=3.0,col=1)
legend("topright",c("Divorce","Marry"),col=1:2,lty=1,lwd=3.0)



#7


data<-Processed_Marriage_Divorce_DB

z=data.frame(matrix(nrow = 100,ncol = 0))

for(x in 1:(ncol(data)-2)){
  c<- (data[, x]-mean(data[, x]))/sd(data[, x])
  z<-cbind(z,c)
}

colnames(z)=names(data[1:30])
summary(z)

lm(formula=z,data=data)

Smodel<-lm(formula=z ,data=data)
model
summary(model)$r.squared
summary(z)

lm(z,data=data)



#8



dta<-data
dta$Education<-attr(dta$Education, "ATT")<-NULL
dta$Independency<-attr(dta$Independency, "ATTT")<-NULL
dta$Recommendation<-attr(dta$Recommendation, "ATTT")<-NULL
dta$Divorce.Score<-attr(dta$Divorce.Score, "ATTT")<-NULL

dta
attach(dta)

library(rpart)
library(rpart.plot)


m<-rpart(data$Recommendation~.,data=dta,
         method = "class")
prp(m)
plot(m)
text(m)
p1 <- predict(m,dta,type = 'class')
confusionMatrix(p1,data$Recommendation)

data<-data.frame(data[c(1:32)])
data$Recommendation<-factor(data$Recommendation)

n<- rpart(data$Recommendation~Age.Gap+Common.Interests,
          data=dta,method = 
          "class")
prp(n)
plot(n)
text(n)
p2 <- predict(n,dta,type = 'class')
confusionMatrix(p2, data$Recommendation)


o<- rpart(data$Recommendation~Loyalty+Desire.to.Marry,
          data=dta,method = 
            "class")
prp(o)
plot(o)
text(o)
p3 <- predict(o,dta,type = 'class')
confusionMatrix(p3, data$Recommendation)

library(rpart)
library(ggplot2)
library(lattice)
library(caret)
install.packages("ggplot2")
install.packages("caret")



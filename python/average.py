# height=[120,150,160,180,98,170]
# count=0
# sum=0
# for each in height:
#     count=count+1
# for each in height:
#     sum=sum+each
# average=sum/count
# # print(int(average))
# print(f"The average is: {int(average)} cm")

heights=input("Enter the heights you want: ")
height=heights.split(",")
print(height)
count=0
sum=0
for each in height:
    count=count+1
for each in height:
    sum=sum+int(each)
average=sum/count
# print(int(average))
print(f"The average is: {round(average)} cm")
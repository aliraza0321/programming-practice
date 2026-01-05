num=input("Enter the numbers for finding largest element: ")
num_list=num.split()
count=0
for i in num_list:
    count=count+1
for each in range(count):
    num_list[each]=int(num_list[each])
print(num_list)
max=num_list[0]
for i in num_list:
    if i>max:
        max=i
print("The largest number is",max)
sum=0
# for i in range(0,101,2):
#     sum+=i
# print(f"Sum of even numbers is: {sum}")

# method 2
for i in range(1,101):
    if i%2==0:
        sum=sum+i
print(f"The sum of even numbers is: {sum}")
import random
print("Welcome to Password Generator!")
letters=int(input("Enter the number how many letters you want to generate in password: "))
symbols=int(input("Enter the number how many symbols you want to generate in password: "))
numbers=int(input("Enter the number how many numbers you want to generate in password: "))
password=""
number=['0','1','2','3','4','5','6','7','8','9']
symbol=['!','@','#','$','%','&','*']
alphebets=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
for i in range(letters):
    password=password+(random.choice(alphebets))
for i in range(symbols):
    password=password+(random.choice(symbol))
for i in range(numbers):
    password=password+(random.choice(number))

print(f"We are generated password for you that is : {password}")

num=int(input("Enter a number"))
choice=input("Do you want to continue to check number or not? (y/n)")
if choice.lower()=="y":
    if num>0:
        print(f"{num} is a positive number")
    elif num<0:
        print(f"{num} is a negative number")
    else:
        print(f"{num} is a zero number")
else:
    print("OK! Goodbye....")
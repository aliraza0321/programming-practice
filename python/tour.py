days=int(input(" For how many days you want to go on tour: "))
price_one_day=int(input("Total expense for one day "))
bill=price_one_day*days
extra_tour=input("Are you want to expend some extra days enter y or Y for y ")
if extra_tour=="y" or extra_tour=="Y":
    bill=bill*(extra_tour*price_one_day)
AC=input("Are you want to use Ac in room ")
if AC=="y" or AC=="Y":
    bill+=10000
print(f"Your total bill is {bill}")
# name="Ali "
# def main():
#     name="Ali"
#     def info():
#         global name
#         name=name+"Raza"
#     print(name)
#     info()
# # print(name)
# main()
# print(name)
a=3
def display():
    a=2
    def show():
        global a
        a=a+9
        print(a)
    print(a)
    show()
    print(a)
display()
print(a)
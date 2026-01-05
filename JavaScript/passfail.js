let result=(marks)=>{
    if(marks>=80)
    {
        console.log("Pass with A grade");
    }
    else if(marks>=60 &&marks<80)
    {
        console.log("Pass with B grade");
    }
    else if(marks>=40 &&marks<60)
    {
        console.log("Pass with C grade");
    }
    else if(marks<40)
    {
        console.log("Fail");
    }
}
let marks=90;
result(marks);
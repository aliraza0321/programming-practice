let num=[1,2,3,4,5,6,7,8,9,10];
let middle=num.length/2;
let start=0;
let end=num.length-1;
console.log("The original array is "+num);
while(start<middle)
{
    let temp=num[start];
    num[start]=num[end];
    num[end]=temp;
    start++;
    end--;
}
console.log("The reversed array is "+num);
//using map method;
let revArray=[];
num.map((value)=>{
    revArray.unshift(value);

});
console.log("The reversed array using map method is "+revArray);
let num=[1,2,3,4,5,6,7,8,9,10];
let even=[];
let odd=[];
for(let i=0;i<num.length;i++)
{
    if(num[i]%2==0)
    {
        even.push(num[i]);
    }
    else{
        odd.push(num[i]);
    }
}
console.log("Even numbers are "+even);
console.log("Odd numbers are "+odd);
let sum=0;
for(let i=0;i<num.length;i++){
    sum=sum+num[i];

}
console.log("The sum of array is "+sum);
//with reducer method
let sumFunc=((pre,cur)=>{
    return pre+cur;
});
let sum1=num.reduce(sumFunc);
console.log("The sum of array using reducer method is "+sum1);

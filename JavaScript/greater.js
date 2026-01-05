let num=[4,5,3,2,1,6,7,8,9,10];
let greater=num[0];
let smallest=num[0];
for(let i=1;i<num.length;i++){
    if(num[i]>greater)
    {
        greater=num[i];
    }
}
for(let i=1;i<num.length;i++)
{
    if(num[i]<smallest){
        smallest=num[i];

    }
}
console.log("The array is "+num);
console.log("The greatest number in the array is "+greater);
console.log("The smallest number in the array is "+smallest);
//using reducer method;

let myfunc=((pre,cur)=>{
    return (pre>cur)?pre:cur;

});

let smallfunc=((pre,cur)=>{
    return (pre<cur)?pre:cur;
});
let greatVal=num.reduce(myfunc);
let smallVal=num.reduce(smallfunc);
console.log("The greatest number using reducer method is "+greatVal);
console.log("The smallest number using reducer method is "+smallVal);
//using filter method
let MaxValue=5;
let myfunc1=((value)=>{
    return (value>MaxValue)?value:undefined;
});
let greaterValues=num.filter(myfunc1);
console.log("The values greater than "+MaxValue+" are "+greaterValues);
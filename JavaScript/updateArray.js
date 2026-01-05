let num=[1,2,3,4,5,6,7,8,9,10];
let doubleNum=[];
for(let i=0;i<num.length;i++){
    doubleNum.push(num[i]*num[i]);
}
console.log("The original array is "+num);
console.log("The updated array with squared values is "+doubleNum);
let square=[];
num.map((value)=>{
    square.push(value*value);

});
console.log("The updated array using map method is "+square);

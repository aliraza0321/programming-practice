let num=[1,0,null,7,"a",false,"b",1,8,"a"];
let sumOfNumbers=(arr,newArr)=>{
    let sum=0;
    for(let i=0;i<arr.length;i++)
    {
        if(typeof arr[i]==="number" && !isNaN(arr[i])){
            sum+=arr[i];
            newArr.push(arr[i]);
        }
      
    }
    return sum;

}
let newArr=[];
console.log("Original array: "+num);
console.log("Sum of numbers in the array: "+sumOfNumbers(num,newArr));
console.log("Array of numbers extracted from the original array: "+newArr);
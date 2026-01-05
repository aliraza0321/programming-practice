let num=[1,3,"a",null,undefined,5,"b",7];
let sum=0;
function addNumbers(arr)
{
    for(let i=0;i<arr.length;i++)
    {
        if(typeof arr[i]==="number")
        {
            sum+=arr[i];
        }
    }
}
addNumbers(num);
console.log("The sum of numbers in the array is: "+sum);
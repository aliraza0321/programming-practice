let num=[1,2,3,4,5,6,7,8,9,10];
let ExtractEven=(arr)=>{
    let evenEvens=[];
    let sum=0;
    for(let i=0;i<arr.length;i++)
    {
        if(arr[i]%2===0)
        {
            evenEvens.push(arr[i]);
            sum+=arr[i];
    }
    }
    console.log("Sum of even numbers: "+sum);
    return evenEvens;
}
let evenNumbers=ExtractEven(num);
let ExtractOdd=(arr)=>{
    let oddNumbers=[];
    let sum=0;
    for(let i=0;i<arr.length;i++)
    {
        if(arr[i]%2!==0)
        {
            oddNumbers.push(arr[i]);
            sum+=arr[i];
    }
    }
    console.log("Sum of odd numbers: "+sum);
    return oddNumbers;
}
function isPrime(num){
    if(num<=1){
        return false
    }
    for(let i=2;i<=Math.sqrt(num);i++){
        if(num%i===0){
            return false;
        }
    }
    return true;

}
let ExtractPrime=(arr)=>{
    let primeNumber=[];
    let sum=0;
    for(let i=0;i<arr.length;i++)
    {
        if(isPrime(arr[i]))
        {
            primeNumber.push(arr[i]);
            sum+=arr[i];
    
        }
    }
    console.log("Sum of prime numbers: "+sum);
    return primeNumber;
}
console.log("Original array: "+num)
console.log("Even numbers: "+evenNumbers);
let oddNumbers=ExtractOdd(num);
console.log("Odd numbers: "+oddNumbers);
let primeNumbers=ExtractPrime(num);
console.log("Prime numbers: "+primeNumbers);
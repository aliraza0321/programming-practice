let num=[1,2,2,3,3,4,4,5,6,6,7,8,8,9,9];
console.log("Original array: "+num);
let unique=(arr)=>{
    for(let i=0;i<arr.length;i++)
    {
        for(let j=i+1;j<arr.length;j++)
        {
            if(arr[i]===arr[j])
            {
                arr.splice(j,1);
                j--;

            }
        }
    }
}
unique(num);
console.log("Array after removing duplicates: "+num);
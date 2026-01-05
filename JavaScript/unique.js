let num=[1,2,2,3,3,4,4,5,6,6,7,8,8,9,9];
let ExtractUnique=(arr)=>{
    let uniqueElements=[];
    for(let i=0;i<arr.length;i++)
    {
        let isUnique=true;
        for(let j=i+1;j<arr.length;j++)
        {
            if(arr[i]===arr[j])
            {
                isUnique=false;
                break;
            }
        }
        if(isUnique)
        {
            uniqueElements.push(arr[i]);
        }
    }
    return uniqueElements;
}
let uniqueNumbers=ExtractUnique(num);
console.log("Original array: "+num);
console.log("Unique numbers: "+uniqueNumbers);
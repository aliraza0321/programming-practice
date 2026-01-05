let num=[1,2,2,3,3,4,4,5,6,6,7,8,8,9,9];
let ExtractDistinct=(arr)=>{
    let distinctElements=[];
    for(let i=0;i<arr.length;i++)
    {
        let isDuplicate=false;
        for(let j=0;j<distinctElements.length;j++)
        {
            if(arr[i]===distinctElements[j])
            {
                isDuplicate=true;
                break;
            }
        }
        if(!isDuplicate)
        {
            distinctElements.push(arr[i]);
        }
    }
    return distinctElements;
}
let distinctNumbers=ExtractDistinct(num);
console.log("Original array: "+num);
console.log("Distinct numbers: "+distinctNumbers);
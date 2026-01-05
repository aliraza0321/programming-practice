let arr=["apple","banana","grape","orange","banana","apple","kiwi","app"];
let searchItem="a";
let result=[];
let search=(arr,searchItem)=>{
    for(let i=0;i<arr.length;i++)
    {
        if(arr[i].includes(searchItem))
        {
            result.push(arr[i]);

        }
    }

}
search(arr,searchItem);
console.log("Items matching '"+searchItem+"': "+result);
let num=[1,2,3,4,5];
let dblnum=[];
let double=(a,call)=>{
    const result=a*a;
    call(result);
}
num.forEach(element => {
     double(element,(output)=>{
        dblnum.push(output);
        
     })    
});
console.log(num);
console.log(dblnum);

//nums will be double using callback 
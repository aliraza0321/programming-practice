let input=document.getElementById("get");
let show=document.getElementById("output");
let btn=document.getElementById("btn");
btn.addEventListener("click",()=>{
 show.innerText="Welcome to "+ input.value +" Developer";
 show.style.color="Red";
 show.style.fontSize="45px";
});
//for access data from input field use input.value not input.innerText
//using input.value we can easilly access inner text tthat we are
//typed in input field
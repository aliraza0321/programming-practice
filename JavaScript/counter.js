
let increase=document.querySelector("#increase");
let decrease=document.querySelector("#decrease");
let show=document.querySelector("#data");
let reset=document.querySelector("#reset");
let screen=document.querySelector("#Screen");
screen.addEventListener("click",()=>{
    if(document.body.style.backgroundColor==="white")
    {
        
      document.body.style.backgroundColor="Black";
    }
    else{
        document.body.style.backgroundColor="white"
    }
    

});
increase.addEventListener("click",()=>{

       let data=show.innerText;
       data++;
       show.innerText=data;
       if(data>0)
       {
        show.style.color="green";
       }
        if(data=0)
       {
        show.style.color="black";
       }

});

decrease.addEventListener("click",()=>{

       let data=show.innerText;
       data--;
       show.innerText=data;
       if(data<0)
       {
        show.style.color="red";
       }
        if(data===0)
       {
        show.style.color="black";
       }

});

reset.addEventListener("click",()=>{

     
       show.innerText=0;
        if(data===0)
       {
        show.style.color="black";
       }

});
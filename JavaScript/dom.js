//dom ky through hum screen change kr sakty hy ya html ka control hota hy using js 
//HTML =body
//Js=dimag
//dom=nervous system that controls html usign js 

let heading = document.getElementById("title"); //for getting tag that has title id
console.log(heading);

//we can also change css using
    heading.style.color = "red";
heading.style.fontSize = "40px";


let heading1=document.getElementById("title1");

let btn = document.getElementById("btn");

//this is event lisnter that excecutes a functions when certain event occurs when btn pressed or clicked this executes
btn.addEventListener("click", () => {
    heading.classList.add("active");

    heading.innerText = "Hello Ali Raza";  //we can change contect of tag using innerText 
  heading1.innerText = "Button dab gaya 😄"; 
});



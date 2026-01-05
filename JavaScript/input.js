let input = document.getElementById("name");
let output = document.getElementById("output");
let showBtn = document.getElementById("show");

showBtn.addEventListener("click", () => {
  output.innerText = "Hello " + input.value;
});
//first get controls for tags and when show button clicked then output will shown inside p tag
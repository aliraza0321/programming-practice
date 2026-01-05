name:"Raza";
const user = {
  name: "Ali",
  greet(){
    let inner=()=>{
        console.log("Hello " + this.name);

  }
    inner();
}
};
user.greet();

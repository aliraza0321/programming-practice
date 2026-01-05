function doHomework(callback) {
  console.log("Homework start");
  callback();
}
let dosomething=()=>{
    console.log("Doing something");
    console.log("Something done");
}
doHomework(dosomething);
function cookFood(callback) {
  setTimeout(() => {
    console.log("Food ready");
    callback();
  }, 3000);
}

cookFood(() => {
  console.log("Eat food");
});
// Expected output order:
// Homework start
// Doing something
// Something done
// (after 3 seconds)
// Food ready
// Eat food
// This demonstrates the use of callbacks to handle asynchronous operations in JavaScript.
// Note: Actual execution order may vary in different environments, but this is the typical behavior in browsers and Node.js.

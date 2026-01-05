 let promise = new Promise((resolve, reject) => {
    console.log("Promise started");
    console.log("Processing...");
  setTimeout(() => {
    resolve("Data mil gaya");
  }, 2000);//yeh function 2 second ke baad chalega
});
//
promise.then((msg) => {
  console.log(msg);//yeh tab chalega jab promise resolve hoga
});
promise.catch((err)=>{
    console.log(err);//yeh tab chalega jab promise reject hoga
});
// Expected output order:
// Promise started
// Processing...
// (after 2 seconds)
// Data mil gaya
// This demonstrates the use of Promises to handle asynchronous operations in JavaScript.
// The promise is rejected after a delay of 2000ms, triggering the catch block.
// Note: Actual execution order may vary in different environments, but this is the typical behavior in browsers and Node.js.

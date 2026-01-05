console.log("1");
console.log("2");
console.log("3");
console.log("1");

setTimeout(() => {
  console.log("2");
}, 2000);

console.log("3");

// Expected output order:
// 1
// 2
// 3
// 1
// 3
// 2
// This demonstrates the synchronous execution of console.log statements
// followed by the asynchronous execution of setTimeout after a delay of 2000ms.
// Note: Actual execution order may vary in different environments, but this is the typical behavior in browsers and Node.js.
setTimeout
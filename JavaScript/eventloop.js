console.log("Start");

setTimeout(() => {
  console.log("Timeout");
}, 0);

Promise.resolve().then(() => {
  console.log("Promise");
});

console.log("End");
// Expected output order:
// Start
// End
// Promise
// Timeout
// This demonstrates the JavaScript event loop and task scheduling.
/// Microtasks (like Promises) are executed before macrotasks (like setTimeout).
// Hence, "Promise" is logged before "Timeout".
// Note: Actual execution order may vary in different environments, but this is the typical behavior in browsers and Node.js.
setTimeout(() => console.log("A"), 100);
setTimeout(() => console.log("B"), 0);

function outer() {
  let count = 0;
  return function () {
    count++;
    return count;
  };
}
const increment = outer(); // inner function is returned here and it is remember the lexical scope of outer funcrion
// Testing the clousure fuctionallity
console.log(increment());
console.log(increment());
console.log(increment());
// `var` is function-scoped, so the loop shares ONE single `i` variable
// setTimeout callback forms a closure over `i` (it captures the variable, not its value)
// By the time callbacks execute, the loop has already finished
// After the loop ends, `i` becomes 4
// Therefore, all callbacks log the same final value: 4

for (var i = 1; i <= 3; i++)
 {
  setTimeout(() => console.log(i), 1000);
}
// `let` is block-scoped, so each loop iteration gets a NEW `i`
// Each setTimeout callback closes over its own `i` value
// That’s why the output becomes: 1, 2, 3
for (let j = 1; j <= 3; j++) {
  setTimeout(() => console.log(j), 1000);
}
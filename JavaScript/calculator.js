let output=document.getElementsByTagName("h1");
let sum = (num1, num2) => {
    return num1 + num2;
}
let subtract = (num1, num2) => {
    return num1 - num2;
}
let multiply = (num1, num2) => {
    return num1 * num2;
}
let divide = (num1, num2) => {
    if (num2 === 0) {

        return 0;
    }
    return num1 / num2;
}
let modulus = (num1, num2) => {
    return num1 % num2;
}
let power = (base, exponent) => {
    return Math.pow(base, exponent);
}
let squareRoot = (num) => {
    return Math.sqrt(num);
}
let factorial = (num) => {
    if (num < 0) {
        return 0;
    }
    let result = 1;
    for (let i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}
let average = (arr) => {
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
    }
    return sum / arr.length;

}
let square = (num) => {
    return num * num;
}
let cube = (num) => {
    return num * num * num;
}
let choice;
function menu() {
    console.log("Calculator Menu:");
    console.log("1. Addition");
    console.log("2. Subtraction");
    console.log("3. Multiplication");
    console.log("4. Division");
    console.log("5. Modulus");
    console.log("6. Power");
    console.log("7. Square Root");
    console.log("8. Factorial");
    console.log("9. Average");
    console.log("10. Square");
    console.log("11. Cube");
    console.log("-1. Exit");
    let choice = parseInt(prompt("Enter your choice: "));
    return choice;
}
do {
    choice = menu();
    if (choice === 1) {
        let num1 = parseFloat(prompt("Enter first number: "));
        let num2 = parseFloat(prompt("Enter second number: "));
        let result = sum(num1, num2);
        output[1].innerText="Result: "+result;
    }
    else if (choice === 2) {
        let num1 = parseFloat(prompt("Enter first number: "));
        let num2 = parseFloat(prompt("Enter second number: "));
        let result = subtract(num1, num2);
        output[1].innerText="Result: "+result;
    }
    else if (choice === 3) {
        let num1 = parseFloat(prompt("Enter first number: "));
        let num2 = parseFloat(prompt("Enter second number: "));
        let result = multiply(num1, num2);
        output[1].innerText="Result of multiplication: "+result;
    }
    else if (choice === 4) {
        let num1 = parseFloat(prompt("Enter first number: "));
        let num2 = parseFloat(prompt("Enter second number: "));
        let result = divide(num1, num2);
        output[1].innerText="Result: "+result;
    }
    else if (choice === 5) {
        let num1 = parseFloat(prompt("Enter first number: "));
        let num2 = parseFloat(prompt("Enter second number: "));
        let result = modulus(num1, num2);
        output[1].innerText="Result of modulus: "+result;
    }
    else if (choice === 6) {
        let base = parseFloat(prompt("Enter base number: "));
        let exponent = parseFloat(prompt("Enter exponent number: "));
        let result = power(base, exponent);
        output[1].innerText="Result of power: "+result;
    }
    else if (choice === 7) {
        let num = parseFloat(prompt("Enter number: "));
        let result = squareRoot(num);
        output[1].innerText="Result of square root: "+result;
    }

    else if (choice === 8) {
        let num = parseInt(prompt("Enter number: "));
        let result = factorial(num);
        output[1].innerText="Result of factorial: "+result;
    }
    else if (choice === 9) {
        let arrInput = prompt("Enter numbers separated by commas: ");
        let arr = arrInput.split(",").map(Number);
        let result = average(arr);
        output[1].innerText="Result of average: "+result;

    }
    else if (choice === 10) {
        let num = parseFloat(prompt("Enter number: "));
        let result = square(num);
        output[1].innerText="Result of square: "+result;
    }
    else if (choice === 11) {
        let num = parseFloat(prompt("Enter number: "));
        let result = cube(num);
        output[1].innerText="Result of cube: "+result;
    }


} while (choice != -1);
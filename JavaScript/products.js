let products = [
    { name: "Pen", price: 20, qty: 3 },
    { name: "Book", price: 200, qty: 2 },
    { name: "Bag", price: 500, qty: 1 },
    { name: "Pencil", price: 10, qty: 5 },
];
let totalAmount = 0;
products.forEach((product) => {

    let productTotal = product.price * product.qty;
    totalAmount += productTotal;


});
console.log("Your all products are ");
products.forEach((product) => {
    console.log(product.name, product.price, product.qty);
});
console.log("Total amount: " + totalAmount);
let products = [
    { name: "Pen", price: 20, qty: 3 },
    { name: "Book", price: 200, qty: 2 },
    { name: "Bag", price: 500, qty: 1 },
    { name: "Pencil", price: 10, qty: 5 },
];
console.log("Your all products are ");
products.forEach((product) => {
    console.log(product.name, product.price, product.qty);
});
let newobj ={
    name: "Notebook",
    price: 150,
    qty: 4

};
products.push(newobj);
console.log("After adding new product:");
products.forEach((product) => {
    console.log(product.name, product.price, product.qty);
});
products.forEach((product)=>{
    product.price=product.price+10;

});
console.log("After updating product prices:");
products.forEach((product) => {
    console.log(product.name, product.price, product.qty);
});
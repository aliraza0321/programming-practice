// console.log("Chai banana start");

// setTimeout(() => {
//   console.log("Chai ready ho gayi");
// }, 3000);

// console.log("Biscuits nikal raha hoon");
//expected output:
// Chai banana start
// Biscuits nikal raha hoon
// (3 sec baad)
// Chai ready ho gayi

// function getData(callback) {
//   setTimeout(() => {
//     callback("Data mil gaya");
//   }, 2000);
// }

// getData((result) => {
//   console.log(result);
// });
//result will be argument for call back and this will print after 2 sec
// let promise = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     resolve("Server se data aa gaya");
//   }, 2000);
// });

// promise.then((data) => {
//   console.log(data);
// });

//after two second promise will resolve and data will print in .then method
// function step1() {
//   return new Promise((resolve) => {
//     setTimeout(() => {
//       resolve("Step 1 complete");
//     }, 1000);
//   });
// }

// function step2(msg) {
//   return new Promise((resolve) => {
//     setTimeout(() => {
//       resolve(msg + " → Step 2 complete");
//     }, 1000);
//   });
// }

// step1()
//   .then(step2)
//   .then((finalResult) => {
//     console.log(finalResult);
//   });
//first step() call that return a promise that is resolved but this will resolve after one  second and then send this to 
//step()2 and send promise of step 1 to step 2 inside step 2 this will pritn 
//and in step2 function resolve promis will return and finalResult will be "Step 1 complete -> step 2 complete"

function fetchData() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("Data aa gaya");
    }, 2000);
  });
}

async function showData() {
  console.log("Fetching...");
  let data = await fetchData();
  return data;
}

// showData();
//show data call first print fetchign.. 
//await will pause and waiting for return promise from fetchData() this will return promise after 2 seconds 
//and after receving promise in data this will print 
// this is synchorous coding every line excecute after completion of previous line 
//asych / await use for this purpose because inside promise promise chaining is very confusing 

async function getUser() {
  try {
    let data = await showData();
    console.log(data);
  } catch (error) {
    console.log("Error a gaya");
  }
}

getUser();
//if promise is reject in fetchdata then catch will work beccause maybe fetchign data is not worked properly then 
//error will come 

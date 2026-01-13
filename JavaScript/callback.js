function fetchData(callback) {
  setTimeout(() => {
    callback("Data received");
  }, 2000);
}

fetchData((data) => {
  console.log(data);

});


/*
callback is function that is passed as a argument to other function and call inside funciton when we need 
we can receive this function using any name  */
function login(username, callback) {
  if (username === "admin") {
    callback(true);
  } else {
    callback(false);
  }
}

login("admin",success);
//we can pass whole function or obj of that function like 
let success=()=>{
     if (success) {
    console.log("Login successful");
  } else {
    console.log("Login failed");
  }

};


function delayedMessage(message, callback) {
  setTimeout(() => {
    callback(message);
  }, 2000);
}

delayedMessage("Hello after 2 seconds", (msg) => {
  console.log(msg);
});
//after 2 sec msg this message will be display

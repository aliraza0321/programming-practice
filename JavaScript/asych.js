//synch js
console.log("a");
console.log("b");
console.log("c");
/*out put will be 
a
b
c 
because in sych mode js works in normal flow when one statement is complete then it will move to next statement 
and then next statement will execute*/

//async

console.log("a");
setTimeout(()=>{
    console("b");
},3000);

console.log("c");
/*
output will be 
a
c
b 
because js did not wait of any function it any time out is used then js runs it in backward and move to next statemtn and execute it 
when that waiting statement's time is finished then it will come on output*/
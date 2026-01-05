let student = {
  name: "Ali",
  marks: [80, 75, 90]
};
let myFunc=((pre,cur)=>{
    return pre+cur;
});
let totalMarks=student.marks.reduce(myFunc);
console.log("Total marks: "+totalMarks);
let lengthOfMarks=student.marks.length;
let averageMarks=totalMarks/lengthOfMarks;
console.log("Average marks: "+averageMarks);
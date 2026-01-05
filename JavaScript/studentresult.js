students = [
  { name: "Ali", marks: [70, 80, 90] },
  { name: "Ahmed", marks: [30, 40, 35] },
    { name: "Aisha", marks: [85, 95, 100] }
];
let passAvg=40;
let sum=(a,b)=>a+b;
function calculateResults(students) {
    let passStudents=[];
    let total=0;
    for(let student of students){
        let studentTotal=student.marks.reduce(sum);
        total+=studentTotal;
        let average=studentTotal/student.marks.length;
        console.log(`Student: ${student.name}, Total Marks: ${studentTotal}, Average Marks: ${average.toFixed(2)}`);
        if(average>=passAvg)
        {
            passStudents.push(student);

        }

    }
    return passStudents;

}
let passedStudents=calculateResults(students);
console.log("Students who passed the exam:");
for(let student of passedStudents){
    console.log(student.name);

}

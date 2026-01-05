let students=[
    {Name:"Ali", Marks:[80,75,90]},
    {Name:"Sara", Marks:[85,95,65]},
    {Name:"John", Marks:[30,20,40]},
    {Name:"Doe", Marks:[70,60,80]}
];
let passedStudents=[];
let pass=150;
students.forEach((student)=>{
    let total=student.Marks.reduce((pre,cur)=>pre+cur,0);
    if(total>=pass){
        passedStudents.push(student);
    }
});
console.log("All Students: ");
students.forEach((student)=>{
    console.log(student.Name, student.Marks);
});
console.log("Passed Students: ");
passedStudents.forEach((student)=>{
    console.log(student.Name, student.Marks);
});

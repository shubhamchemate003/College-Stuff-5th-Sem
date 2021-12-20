const mongoose = require("mongoose");
mongoose.connect("mongodb://localhost:27017/b02_db", { useNewUrlParser: true });

var randomName = function () {
	// Base 36 uses letters and digits to represent a number:
	return (Math.random() + 1).toString(36).substring(2);
};

var randomNumber = function (l, r) {
	return Math.floor(Math.random() * (r - l)) + l;
};

const studentSchema = new mongoose.Schema({
	name: String,
	subject: String,
	marks: Number,
});

const Student = mongoose.model("student", studentSchema);

const names = [
	"Tony",
	"Natasha",
	"Steve",
	"Peter",
	"Thor",
	"Wanda",
	"Vision",
	"Bucky",
	"Thanos",
	"TChalla",
	"Bruce",
	"Shuri",
	"Scott",
	"Stephen",
	"Clint",
	"Loki",
];

const subjects = ["OOPS", "CN", "OS", "DBMS", "DSA"];

for (let i = 0; i < names.length; i++) {
	for (let j = 0; j < subjects.length; j++) {
		const student = new Student({
			name: names[i],
			subject: subjects[j],
			marks: randomNumber(70, 100),
		});

		student.save();
	}
}

console.log("Insertion done");

create table student (
    roll_no int not null auto_increment,
    name varchar(100),
    grade varchar(10)
);

insert into student (name, grade)
values ('Tony', 'A+'),
('Natasha', 'B'),
('Steve', 'A+'),
('Peter', 'B'),
('Stephen Strange', 'A');
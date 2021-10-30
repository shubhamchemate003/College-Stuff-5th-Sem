-- Write a Stored Procedure namely proc_Grade for the categorization of student. If
-- marks scored by students in examination is <=1500 and marks>=990 then student
-- will be placed in distinction category if marks scored are between 989 and900 
-- category is first class, if marks899and 825 category is Higher Second Class.
-- Write a PL/SQLblock to use procedure created with above requirement.
-- Stud_Marks(name, total_marks) Result(Roll,Name, Class)
-- Note: Instructor will frame the problem statement for writing stored procedure and
-- Function in line with above statement.

CREATE TABLE stud_marks(
    roll_num INT NOT NULL PRIMARY KEY,
    stud_name VARCHAR(200),
    total_marks INT
);

CREATE TABLE result(
    roll_num INT NOT NULL PRIMARY KEY,
    stud_name VARCHAR(200),
    class VARCHAR(300)
);

INSERT INTO stud_marks(roll_num, stud_name, total_marks)
VALUES (1, 'Alex', 1300),
(2, 'Bob', 980),
(3, 'Natasha', 840);

DELIMITER //

CREATE PROCEDURE proc_grade(
    IN rn INT
)

BEGIN

    DECLARE sn VARCHAR(200);
    DECLARE marks INT;
    DECLARE cl VARCHAR(300);

    SELECT stud_name, total_marks
    INTO sn, marks
    FROM stud_marks
    WHERE stud_marks.roll_num = rn;

    IF marks >= 990 AND marks <= 1500 THEN 
        SET cl = 'distinction category';
    ELSEIF marks >= 900 AND marks <= 989 THEN
        SET cl = 'first class';
    ELSEIF marks >= 825 AND marks <= 899 THEN
        SET cl = 'higher second class';
    ELSE 
        SET cl = 'undefined';
    END IF;

    INSERT INTO result (roll_num, stud_name, class)
    VALUES (rn, sn, cl);

END //

DELIMITER ;

CALL proc_grade(1);
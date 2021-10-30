-- Cursors: (All types: Implicit, Explicit, Cursor FOR Loop, Parameterized Cursor)
-- Write a PL/SQL block of code using parameterized Cursor, that will merge the data 
-- available in the newly created table 
-- N_EmpId with the data available in the table O_EmpId.
-- If the data in the first table already exist in the second table then that data should be 
-- skipped.

CREATE TABLE new_emps(
    emp_id INT PRIMARY KEY NOT NULL, 
    emp_name VARCHAR(200)
);

CREATE TABLE old_emps(
    emp_id INT PRIMARY KEY NOT NULL, 
    emp_name VARCHAR(200)
);

INSERT INTO old_emps(emp_id, emp_name)
VALUES (1, 'Natasha'), (2, 'Tony'), (3, 'Steve');

INSERT INTO new_emps(emp_id, emp_name)
VALUES (4, 'Peter'), (5, 'Vision'), (3, 'Steve');

DELIMITER //

CREATE PROCEDURE update_old()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE cur_emp_id INT;
    DECLARE cur_emp_name VARCHAR(200);

    DECLARE cur CURSOR FOR 
    SELECT emp_id, emp_name FROM new_emps WHERE emp_id NOT IN (SELECT emp_id FROM old_emps);

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN cur;

    emp_loop: LOOP 
        FETCH cur INTO cur_emp_id, cur_emp_name;

        IF done THEN
            LEAVE emp_loop;
        END IF;

        INSERT INTO old_emps(emp_id, emp_name)
        VALUES(cur_emp_id, cur_emp_name);
    END LOOP;

    CLOSE cur;
END //

DELIMITER ;
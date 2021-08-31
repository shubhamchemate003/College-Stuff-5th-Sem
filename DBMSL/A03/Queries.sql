-- Find the professor details and department details using NATURAL JOIN.
SELECT prof_fname, prof_lname, dept_name
FROM professors
NATURAL JOIN departments;

-- Find the prof_id, prof_name and shift. (INNER JOIN)
SELECT professors.prof_id AS prof_id, CONCAT(prof_fname, ' ', prof_lname) AS prof_name, shift
FROM professors
INNER JOIN shift
ON professors.prof_id = shift.prof_id;

-- List all the department details and the corresponding names of professors in the same
-- department.(left outer join)
SELECT dept_name, CONCAT(prof_fname, ' ', prof_lname) AS prof_name
FROM departments
LEFT JOIN professors
ON departments.dept_id = professors.dept_id;

-- List all the professors and the corresponding names of department.(right outer join)
SELECT CONCAT(prof_fname, ' ', prof_lname) AS prof_name, dept_name
FROM professors
RIGHT JOIN departments
ON professors.dept_id = departments.dept_id;

--  Display professor name, dept_name, shift, salary where prof_id = 101;(multitable join)
SELECT CONCAT(prof_fname, ' ', prof_lname) AS prof_name, dept_name, shift, salary
FROM professors
INNER JOIN departments ON professors.dept_id = departments.dept_id
INNER JOIN shift ON professors.prof_id = shift.prof_id;

-- list the total number of professor in each department.(count and any join,groupby)
SELECT departments.dept_name AS 'Department', COUNT(*) AS 'Available Professors'
FROM professors
INNER JOIN departments ON professors.dept_id = departments.dept_id
GROUP BY departments.dept_id;

-- List the prof_id associated department and the dept_name having name ‘computer’;(subquery)
SELECT prof_id, dept_id
FROM professors
WHERE professors.dept_id IN (SELECT dept_id FROM departments WHERE dept_name='CSE');

-- Find the names of all departments where the professors joined in year 2015 (or date of joining is 1-1-2015).(subquery)
SELECT dept_name
FROM departments
WHERE dept_id IN (SELECT dept_id FROM professors WHERE doj='2015-01-01');
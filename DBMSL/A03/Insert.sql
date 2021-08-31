INSERT INTO departments(dept_name)
VALUES
('CSE'),
('Chem Eng.'),
('EE'),
('AE'),
('Civil Eng.');

INSERT INTO professors(prof_fname, prof_lname, dept_id, designation, salary, email, phone, city, doj)
VALUES
('Sudarshan', 'Kumar', 4, 'HOD', 40.41, 'head.aero@iitb.ac.in', '(+91 22) 25767124 (O)', 'Mumbai', '2010-08-01'),
('Madhu', 'Vinjamur', 2, 'HOD', 40.41, 'head.chem@iitb.ac.in', '(+91 22) 25767124 (O)', 'Mumbai', '2008-09-01'),
('Deepankar', 'Choudhury', 5, 'HOD', 40.41, 'head.civil@iitb.ac.in', '(+91 22) 25767124 (O)', 'Mumbai', '2001-01-01'),
('Umesh', 'Bellur', 1, 'HOD', 40.41, 'head.cse@iitb.ac.in', '(+91 22) 25767124 (O)', 'Mumbai', '2009-08-01'),
('Kishore', 'Chatterjee', 3, 'HOD', 40.41, 'head.ee@iitb.ac.in', '(+91 22) 25767124 (O)', 'Mumbai', '2005-03-01'),
('Vinay', 'Ribeiro', 1, 'AP', 30.31, 'vinayr@cse.iitb.ac.in', '(+91 22) 25767124 (O)', 'Mumbai', '2015-01-01'),
('Vivek', 'Agarwal', 3, 'Professor', 35.41, 'agarwal@ee.iitb.ac.in', '(+91 22) 25767124 (O)', 'Mumbai', '2015-01-01');

INSERT INTO works(prof_id, dept_id, duration_yrs)
VALUES
(1, 4, 5),
(2, 2, 4),
(3, 5, 3),
(4, 1, 6),
(5, 3, 3),
(6, 1, 5),
(7, 3, 7);

INSERT INTO shift(prof_id, shift, working_hours)
VALUES
(1, 'Morning', 8),
(2, 'Afternoon', 8),
(3, 'Morning', 8),
(4, 'Afternoon', 8),
(5, 'Morning', 8),
(6, 'Afternoon', 5),
(7, 'Afternoon', 5);
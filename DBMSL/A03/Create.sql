CREATE TABLE departments 
(
    dept_id INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    dept_name VARCHAR(200)
);

CREATE TABLE professors
(
    prof_id INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    prof_fname VARCHAR(200),
    prof_lname VARCHAR(200),
    dept_id INT NOT NULL,
    designation VARCHAR(200),
    salary DECIMAL(5, 2),
    doj DATE,
    email VARCHAR(200),
    phone VARCHAR(30),
    city VARCHAR(100),
    FOREIGN KEY (dept_id) REFERENCES departments(dept_id) ON DELETE CASCADE
);

CREATE TABLE works
(
    prof_id INT NOT NULL,
    dept_id INT NOT NULL,
    duration_yrs INT NOT NULL,
    FOREIGN KEY (prof_id) REFERENCES professors(prof_id) ON DELETE CASCADE,
    FOREIGN KEY (dept_id) REFERENCES departments(dept_id) ON DELETE CASCADE
);

CREATE TABLE shift
(
    prof_id INT NOT NULL,
    shift VARCHAR(100),
    working_hours INT,
    FOREIGN KEY (prof_id) REFERENCES professors(prof_id) ON DELETE CASCADE
);
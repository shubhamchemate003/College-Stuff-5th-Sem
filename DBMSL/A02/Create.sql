CREATE TABLE Customer
(
    cust_no INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    cust_fname VARCHAR(100),
    cust_lname VARCHAR(100),
    cust_company VARCHAR(100),
    cust_addr VARCHAR(200),
    city VARCHAR(100),
    cust_phone VARCHAR(15)
);

CREATE TABLE Author
(
    author_no INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    author_name VARCHAR(100),
    country VARCHAR(50)
);

CREATE TABLE Publisher 
(
    publisher_no INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    publisher_name VARCHAR(100),
    publisher_addr VARCHAR(500),
    est_year INT
);

CREATE TABLE Books
(
    ISBN VARCHAR(50) NOT NULL PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    unit_price INT NOT NULL,
    author_no INT NOT NULL,
    publisher_no INT NOT NULL,
    publ_year INT,
    FOREIGN KEY (author_no) REFERENCES Author (author_no) ON DELETE CASCADE,
    FOREIGN KEY (publisher_no) REFERENCES Publisher (publisher_no) ON DELETE CASCADE
);

CREATE TABLE Ordering
(
    order_no INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    cust_no INT NOT NULL,
    ISBN VARCHAR(50) NOT NULL,
    quantity INT,
    ord_date DATE,
    FOREIGN KEY (cust_no) REFERENCES Customer (cust_no) ON DELETE CASCADE,
    FOREIGN KEY (ISBN) REFERENCES Books (ISBN) ON DELETE CASCADE
);
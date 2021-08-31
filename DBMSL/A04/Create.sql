CREATE TABLE Borrower
(
    roll_no INT NOT NULL PRIMARY KEY,
    date_of_issue DATE NOT NULL,
    name_of_book VARCHAR(500),
    status VARCHAR(2) 
);

CREATE TABLE FineTable
(
    roll_no INT NOT NULL,
    date_of_fine TIMESTAMP DEFAULT NOW(),
    amt INT
);
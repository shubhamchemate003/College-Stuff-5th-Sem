INSERT INTO Customer(cust_fname, cust_lname, cust_company, cust_addr, city, cust_phone)
VALUES
('Harry', 'Potter', 'HSWW', 'Great Britain', 'Scotland', '62442-62442'),
('John', 'Wick', 'Lionsgate', 'Tilak Road', 'Pune', '8888888888'),
('Prince', 'Kaiser', 'Handsopher', 'MG Road', 'Pune', '9758398398'),
('Steve', 'Rogers', 'Captain America', 'US Road', 'Mumbai', '9876543210'),
('Tony', 'Stark', 'Iron Man', 'New York City Road', 'Delhi', '9999999999'),
('King', 'TChalla', 'Black Panther', 'Wakanda Road', 'Mumbai', '9876678912'),
('Natasha', 'Romanoff', 'Black Wodow', 'Avenger Tower', 'Kolkata', '8989898989'),
('Bruce', 'Banner', 'Hulk', 'Dyton', 'Mumbai', '8917372989'),
('Thor', 'Odinson', 'Thunder', 'Asgard', 'Pune', '9877800970'),
('Scot', 'Lang', 'Ant-Man', 'Quantum World, Worm Hole', 'MP', '9878988900')
;

INSERT INTO Customer(cust_fname, cust_lname, cust_company, cust_addr, city, cust_phone)
VALUES ('Peter', 'Parker', 'Sony', 'xyz road', 'Pune', '9876678909');

INSERT INTO Author(author_name, country)
VALUES
('Hector Garcia', 'Japan'),
('James Clear', 'Australia'),
('Morgan Housel', 'Russia'),
('Robert Kiyosaki', 'Australia'),
('George RR Martin', 'USA'),
('Chetan Bhagan', 'India'),
('JK Rowling', 'USA'),
('JRR Tolkien', 'England'),
('Paulo Coelho', 'Portuguese');

INSERT INTO Publisher(publisher_name, publisher_addr, est_year)
VALUES
('ABC Publication', 'Pune', 2015),
('XYZ Publication', 'Mumbai', 2016),
('Red Heart Publication', 'Kolkata', 2014),
('Common Man Publication', 'Delhi', 2011),
('VV Publication', 'Meghalaya', 2019),
('ABC Publication', 'Pune', 2016);

INSERT INTO Books(ISBN, title, unit_price, author_no, publisher_no, publ_year)
VALUES
('123-456-789-123-4', 'Ikigai', 320, 1, 1, 2000),
('234-567-890-123-4', 'Atomic Habits', 380, 2, 2,2004),
('345-678-901-234-5', 'The Psycology of Money', 400, 3, 3,2006),
('456-789-012-345-6', 'Rich Dad and Poor Dad', 280, 4, 4,2000),
('567-890-123-456-7', 'The Game of Thrones', 1100, 5, 4,2006)
('678-901-234-567-8', 'Lord Of The Rings', '1500', 8, 1, 1999),
('789-012-345-678-9', 'The Alchemist', '400', 9, 2, 1995),
('123-456-789-123-5', 'Radom', 320, 7, 5, 2015);

INSERT INTO Ordering(cust_no, ISBN, quantity, ord_date)
VALUES
(4, '567-890-123-456-7', 5, '2021-08-20'),
(9, '678-901-234-567-8', 3, '2021-08-22');

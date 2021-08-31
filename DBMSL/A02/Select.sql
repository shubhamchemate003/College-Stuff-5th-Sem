-- Selection queries

SELECT *
FROM Customer
WHERE (city='Pune' OR city='Mumbai') AND (cust_fname LIKE 'p%' OR cust_fname LIKE 'h%');

SELECT DISTINCT city
FROM Customer;

SELECT author_name, country
FROM Author
WHERE country='India'
UNION
SELECT author_name, country
FROM Author
WHERE country='Australia'

SELECT publisher_name, est_year
FROM Publisher
WHERE est_year=2015 
AND publisher_name IN (SELECT publisher_name
FROM Publisher
WHERE est_year=2016);

SELECT *
FROM Books
WHERE unit_price=(SELECT MAX(unit_price) FROM Books);

SELECT title, unit_price
FROM Books
WHERE unit_price BETWEEN 300 AND 400;

SELECT title, unit_price, publ_year
FROM Books
ORDER BY publ_year DESC;

SELECT title, author_no, publisher_no
FROM Books
WHERE publ_year IN(2000, 2004, 2006);

CREATE VIEW books_and_authors AS 
SELECT title, author_name
FROM Books, Author
WHERE Books.author_no=Author.author_no;

SELECT * FROM books_and_authors;

-- Update queries

UPDATE Books
SET unit_price = 1.05*unit_price
WHERE publ_year=2015;

-- Deletion queries

DELETE FROM Customer
WHERE city='Pune';
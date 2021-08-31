SELECT *
FROM Books
WHERE publ_year=2015;

UPDATE Books
SET unit_price = 1.05*unit_price
WHERE publ_year=2015;

SELECT *
FROM Books
WHERE publ_year=2015;
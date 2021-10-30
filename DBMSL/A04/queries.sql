-- simple procedure in pl/sql

DELIMITER //

CREATE PROCEDURE getBorrowerDetails()

BEGIN
    SELECT * FROM Borrower;
END //

DELIMITER ;

CALL getBorrowerDetails();











-- Accept Roll_no and NameofBook from user
-- Check the number of days(from date of issue)
-- If days are between 15 to 30 then fine amount will be Rs 5 per day
-- If no.ofdays > 30 per day fine will be Rs 50 per day
-- After submitting the book, status will change from I to R
-- If condition of fine is true,then details will be stored into fine table.

-- Calculating Fine of single roll number

CREATE PROCEDURE calculateFine (
    IN cur_roll_no INT
)

BEGIN

    DECLARE days_passed INT DEFAULT 0;
    DECLARE fine INT DEFAULT 0;

    DECLARE EXIT HANDLER FOR 1062
    BEGIN
        SELECT 'This roll number has multiple entries in database.' AS 'EXCEPTION';
    END;

    DECLARE EXIT HANDLER FOR NOT FOUND
    BEGIN
        SELECT 'This user is not present in database.' AS 'EXCEPTION';
    END;

    SELECT DATEDIFF(NOW(), date_of_issue)
    INTO days_passed
    FROM Borrower
    WHERE roll_no=cur_roll_no;

    IF days_passed>30 THEN
        SET fine = (days_passed-30)*50 + 15*5;
    ELSEIF days_passed>=15 THEN
        SET fine = (days_passed-14)*5;
    ELSE
        SET fine = 0;
    END IF;

    UPDATE Borrower SET status = 'R'
    WHERE roll_no = cur_roll_no;

    IF fine > 0 THEN
        INSERT INTO FineTable(roll_no, amt)
        VALUES(cur_roll_no, fine);
    END IF;

END //






















-- Looping over all borrowers to calculate fine

CREATE PROCEDURE calculateFineAll()

BEGIN

    DECLARE fine INT DEFAULT 0;
    DECLARE n INT DEFAULT 0;
    DECLARE days_passed INT DEFAULT 0;
    DECLARE i INT DEFAULT 0;
    DECLARE cur_roll INT DEFAULT 0;

    SELECT COUNT(*) FROM Borrower INTO n;

    SET i = 0;
    WHILE i<n DO
        SELECT DATEDIFF(NOW(), date_of_issue), roll_no
        INTO days_passed, cur_roll
        FROM Borrower 
        LIMIT i, 1;

        IF days_passed>30 THEN
            SET fine = days_passed*50;
        ELSEIF days_passed>=15 THEN
            SET fine = days_passed*5;
        ELSE
            SET fine = 0;
        END IF;

        UPDATE Borrower SET status = 'R'
        WHERE roll_no = cur_roll;



        IF fine > 0 THEN
            INSERT INTO FineTable(roll_no, amt)
            VALUES(cur_roll, fine);
        END IF;

        SET i = i+1;
    END WHILE;

    
END //

DROP PROCEDURE calculateFine;
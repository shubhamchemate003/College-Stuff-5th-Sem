CREATE TABLE areas (
    rad DECIMAL(5, 2),
    area DECIMAL(8, 2)
);

DELIMITER //

CREATE PROCEDURE calculate_area (
    IN rad DECIMAL(5, 2)
)

BEGIN

    DECLARE area DECIMAL(8, 2) DEFAULT 0.0;

    IF (rad > 4 AND rad < 10) THEN
        SET area = (SELECT PI()) * rad * rad;

        INSERT INTO areas(rad, area)
        VALUES(rad, area);
    ELSE
        SELECT "Radius value should be between 5 and 9." AS "MSG";
    END IF;

END //

DELIMITER ;
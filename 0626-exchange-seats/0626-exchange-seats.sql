# Write your MySQL query statement below
SELECT
    -- We are changing the id based on whether it's even or odd.
    CASE
        -- If the id is odd (like 1, 3, 5, ...) and there is a next student,
        -- we swap it with the next id (i.e., id + 1)
        WHEN id % 2 = 1 AND id + 1 <= (SELECT MAX(id) FROM Seat) THEN id + 1

        -- If the id is even (like 2, 4, 6, ...), we swap it with the previous id (i.e., id - 1)
        WHEN id % 2 = 0 THEN id - 1

        -- If it's an odd id but the last one in the table (i.e., no next student to swap with),
        -- we leave it unchanged.
        ELSE id
    END AS id,  -- This gives us the new id after swapping
    student     -- The student name remains the same
FROM Seat
ORDER BY id;   -- We sort the final output by the new id to get the correct order

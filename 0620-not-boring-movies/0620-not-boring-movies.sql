# Write your MySQL query statement below
SELECT *
FROM cinema
WHERE id%2!=0 AND description!="boring"
ORDER BY rating DESC
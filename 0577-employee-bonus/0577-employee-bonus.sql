SELECT name,bonus
FROM Employee as E
LEFT JOIN Bonus AS B
ON E.empId =B.empId 
WHERE bonus <1000 OR B.Bonus is NULL
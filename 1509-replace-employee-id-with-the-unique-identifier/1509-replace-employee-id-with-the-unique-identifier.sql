
SELECT eu.unique_id,e.name 
FROM Employees e
LEFT JOIN EmployeeUNI eu
ON e.id=eu.id






-- SELECT euni.unique_id, e.name
-- FROM Employees e
-- LEFT JOIN EmployeeUNI euni
-- ON e.id = euni.id;

SELECT project_id,
ROUND(AVG(E.experience_years),2) AS  average_years
FROM Project AS P
LEFT JOIN Employee AS E
ON  p.employee_id =E.employee_id 
GROUP BY  project_id
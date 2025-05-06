WITH Weight_CTE AS (
  SELECT *,
         SUM(weight) OVER (ORDER BY turn) AS cumulative_weight
  FROM Queue
)
SELECT person_name
FROM Weight_CTE
WHERE cumulative_weight <= 1000
ORDER BY turn DESC
LIMIT 1;

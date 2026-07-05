SELECT p.project_id,
       ROUND(
           IFNULL(SUM(e.experience_years) / COUNT(e.experience_years), 0),
           2
       ) AS average_years
FROM Project p
JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id;
# Write your MySQL query statement below
SELECT u.unique_id, emp.name
FROM Employees emp
LEFT JOIN EmployeeUNI u
ON emp.id = u.id;
# Write your MySQL query statement below
SELECT 
ifnull(
    (select distinct salary 
FROM Employee
ORDER BY salary DESC
LIMIT 1 OFFSET 1),NULL)as SecondHighestSalary

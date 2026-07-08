# Write your MySQL query statement below
SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
JOIN Department d
ON e.departmentId = d.id
where  e.salary>=(
    select max(salary)
    from Employee
    where departmentId=e.departmentId
)

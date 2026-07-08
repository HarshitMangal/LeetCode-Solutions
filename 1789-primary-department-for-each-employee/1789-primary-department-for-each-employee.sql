# Write your MySQL query statement below
SELECT
    employee_id,
    department_id
FROM Employee e
WHERE primary_flag = 'Y' or
  (select count(*)
  from Employee
  where employee_id=e.employee_id)
  =1;

# Write your MySQL query statement belows
# fre vala
select email as Email
from Person
group by email
having count(*) >= 2;


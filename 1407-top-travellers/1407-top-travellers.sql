# Write your MySQL query statement below
select u.name,
   ifNULL(
   sum(r. distance),0)
   as travelled_distance
   from Users u
   left join Rides r
   on u.id=user_id
   group by u.id,u.name
   ORDER BY travelled_distance DESC, u.name;

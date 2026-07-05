# Write your MySQL query statement below
select u.product_id ,
 ROUND(
        IFNULL(SUM(p.price * u.units) / SUM(u.units), 0),
        2
    ) AS average_price
from Prices p
 left join UnitsSold u
on p.product_id=u.product_id
where u.purchase_date BETWEEN p.start_date AND p.end_date
group by p.product_id


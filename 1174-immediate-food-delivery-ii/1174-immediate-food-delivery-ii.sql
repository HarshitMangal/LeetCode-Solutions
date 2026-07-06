# Write your MySQL query statement below

SELECT
    ROUND(
        AVG(
            CASE
                WHEN order_date = customer_pref_delivery_date THEN 100
                ELSE 0
            END
        ),
        2
    ) AS immediate_percentage
FROM Delivery d
where (customer_id,order_date) in
(
    SELECT customer_id, MIN(order_date)
    FROM Delivery
    GROUP BY customer_id
);
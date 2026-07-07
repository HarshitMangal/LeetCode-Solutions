SELECT
    user_id,
    time_stamp AS last_stamp
FROM Logins
WHERE (user_id, time_stamp) IN (
    SELECT
        user_id,
        MAX(time_stamp)
    FROM Logins
    where year(time_stamp)=2020
    GROUP BY user_id
);
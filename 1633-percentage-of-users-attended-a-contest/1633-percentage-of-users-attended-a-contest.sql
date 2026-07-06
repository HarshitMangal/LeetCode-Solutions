# Write your MySQL query statement below
SELECT
    r.contest_id,
    ROUND(COUNT(r.user_id) * 100 / t.total_users, 2) AS percentage
FROM Register r
JOIN (
    SELECT COUNT(*) AS total_users
    FROM Users
) t
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC;

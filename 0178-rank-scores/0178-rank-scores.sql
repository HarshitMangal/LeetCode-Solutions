# Write your MySQL query statement below
select  s1.score,
    (
        SELECT COUNT(DISTINCT s2.score)
        FROM Scores s2
        WHERE s2.score > s1.score
    ) + 1 AS `rank`
from Scores s1
order by s1.score desc

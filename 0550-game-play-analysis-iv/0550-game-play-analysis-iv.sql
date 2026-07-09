SELECT
    ROUND(
        COUNT(DISTINCT a.player_id) /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM Activity a
WHERE DATEDIFF(
        a.event_date,
        (
            SELECT MIN(event_date)
            FROM Activity
            WHERE player_id = a.player_id
        )
    ) = 1;
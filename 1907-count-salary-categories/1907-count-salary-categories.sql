SELECT 'Low Salary' AS category,
       COUNT(*) AS accounts_count
FROM Accounts a
WHERE a.income < 20000

UNION ALL

SELECT 'Average Salary',
       COUNT(*)
FROM Accounts a
WHERE a.income BETWEEN 20000 AND 50000

UNION ALL

SELECT 'High Salary',
       COUNT(*)
FROM Accounts a
WHERE a.income > 50000;
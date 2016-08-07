# Write your MySQL query statement below
select Id
from Weather w1
where
    Temperature >
    (
    select Temperature
    from Weather w2
    where TO_DAYS(w2.Date) + 1 = TO_DAYS(w1.Date)
    )
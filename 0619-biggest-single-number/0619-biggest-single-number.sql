# Write your MySQL query statement below
select max(num) as num
from Mynumbers
 where num in(



select num
from Mynumbers
group by num
having count(num)=1
 ) 
# Write your MySQL query statement below
(select name as results
from users as u
 join movierating as m using(user_id)
 
 group by user_id
 order by count(rating) desc, name
 limit 1)

UNION all 
(
select title as results
from movies m
join movierating as mr using(movie_id)
where month(created_at)='02' and year(created_at)='2020'
group by title
order by avg(rating)desc, title
limit 1
)

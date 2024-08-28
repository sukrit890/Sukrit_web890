(select u.name as results
from users u 
join movierating m on u.user_id=m.user_id
group by u.user_id
having count(m.rating)=(
    select count(rating)
    from movierating
    group by user_id
    order by count(rating) desc
    limit 1
)
order by u.name asc 
limit 1)

union all
(
select mo.title as results
from movies mo
join movierating m on mo.movie_id=m.movie_id
where extract(year_month from m.created_at)=202002
group by mo.movie_id
having avg(rating)=(
    select avg(rating)
    from movierating
    where extract(year_month from created_at)=202002
    group by movie_id
    order by avg(rating) desc
    limit 1
)
order by mo.title asc
limit 1)
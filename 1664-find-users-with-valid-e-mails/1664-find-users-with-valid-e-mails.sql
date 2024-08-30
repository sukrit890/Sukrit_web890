# Then I tried this, but now the error was coming at the end of the code. It didn't check if the domain name was correct after com, and it also accepted the wrong domain names.
select * 
from Users 
where mail regexp '^[A-Za-z][A-Za-z0-9.\_\-]*@leetcode[.]com$'
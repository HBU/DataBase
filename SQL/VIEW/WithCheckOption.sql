create view View_Stu_1
as
select Sno,Sname,Ssex,Sage,Sdept
from Student
where Sdept='IS'

go

create view View_Stu_2
as
select Sno,Sname,Ssex,Sage,Sdept
from Student
where Sdept='IS'
with check option;

go

insert into View_Stu_1(Sno,Sname,Ssex,Sage)--无With check option: Sdept会自动补充Null
values ('95007111','张兰11','F','19')

insert into View_Stu_2(Sno,Sname,Ssex,Sage) --有With check option: 如果没有Sdept会报错，不能够为Sdept自动补充IS。
values ('950072','李勇','F','19')

insert into View_Stu_2(Sno,Sname,Ssex,Sage,Sdept) --有With check option: 有Sdept为IS，可以正常执行。
values ('950072','李勇','F','19','IS')

select * from Student
select * from View_Stu_1
select * from View_Stu_2

----第3大题

--建立库
create database SPJbase
use SPJbase


--建立表
create table s                 --建立s表
(
sno varchar(5) primary key,
sname varchar(10) not null,
status int not null,
city varchar(10) not null
)
create table p                 --建立p表
(
pno varchar(5) primary key,
pname varchar(10) not null,
color varchar(50) not null,
weight int not null
)
create table j                 --建立j表
(
jno varchar(5) primary key,
jname varchar(10) not null,
city varchar(10) not null
)
create table spj               --建立spj表
(
sno varchar(5),
pno varchar(10) not null,
jno varchar(10) not null,
qty int  not null 
)



--插入数据

insert into s values('s1','精益',20,'天津')   --插入S表
insert into s values('s2','盛锡',10,'北京')
insert into s values('s3','东方红',30,'北京')
insert into s values('s4','丰泰盛',20,'天津')
insert into s values('s5','为民',30,'上海')
select * from s

insert into p values('p1','螺母','红',12)     --插入P表
insert into p values('p2','螺栓','绿',17)
insert into p values('p3','螺丝刀','蓝',14)
insert into p values('p4','螺丝刀','红',14)
insert into p values('p5','凸轮','蓝',40)
insert into p values('p6','齿轮','红',30)
select * from p

insert into j values('j1','三建','北京')      --插入J表
insert into j values('j2','一汽','长春')
insert into j values('j3','弹簧厂','天津')
insert into j values('j4','造船厂','天津')
insert into j values('j5','机车厂','唐山')
insert into j values('j6','无线电厂','常州')
insert into j values('j7','半导体厂','南京')
select * from j

insert into spj values('s1','p1','j1',200)   --插入spj表
insert into spj values('s1','p1','j3',100)
insert into spj values('s1','p1','j4',700)
insert into spj values('s1','p2','j2',100)
insert into spj values('s2','p3','j1',400)
insert into spj values('s2','p3','j2',200)
insert into spj values('s2','p3','j4',500)
insert into spj values('s2','p3','j5',400)
insert into spj values('s2','p5','j1',400)
insert into spj values('s2','p5','j2',100)
insert into spj values('s3','p1','j1',200)
insert into spj values('s3','p3','j1',200)
insert into spj values('s4','p5','j1',100)
insert into spj values('s4','p6','j3',300)
insert into spj values('s4','p6','j4',200)
insert into spj values('s5','p2','j4',100)
insert into spj values('s5','p3','j1',200)
insert into spj values('s5','p6','j2',200)
insert into spj values('s5','p6','j4',500)
select * from spj

---------------------------------------------------------------------------------------------------------------------------------


--第4大题

----(1)题
select distinct sno from spj where jno ='j1'

----(2)题
select distinct sno from spj where jno ='j1'and pno='p1'

----(3)题
select distinct sno 
from spj 
where jno ='j1'
      and pno in
         (select pno 
          from p 
          where color='红')

----(4)题
select jno
from j
where not exists
(select *
 from spj,s,p
 where spj.jno=j.jno
   and spj.sno=s.sno
   and spj.pno=p.pno
   and s.city='天津'
   and p.color='hong');

----(5)题
SELECT JNO 
FROM SPJ SPJX
WHERE NOT EXISTS
	(SELECT *
	FROM SPJ SPJY
	WHERE SPJY.SNO='S1'AND NOT EXISTS
	(SELECT *
	FROM SPJ SPJZ
	WHERE SPJZ.SNO=SPJX.SNO
	AND SPJZ.CNO=SPJY.CNO))



---------------------------------------------------------------------------------------------------------------------------------


--第5大题

----(1)题
select sname,city from s 

----(2)题
select pname,color,weight from p

(3)
SELECT JNO
FROM SPJ
WHERE SNO='S1';
(4)
SELECT P.PNAME,SPJ.QTY
FROM SPJ,P
WHERE SPJ.PNO=P.PNO AND JNO='J2';
(5)
SELECT DISTINCT PNO
FROM SPJ
WHERE SNO IN
	(SELECT SNO
	FROM S
	WHERE CITY='上海');

----(6)题
select jname from j where jno in(select jno from spj where sno in(select sno from s where city='上海'))

----(7)题
select jno
from j
where not exists
       (select *
        from spj,s
        where spj.jno=j.jno and spj.sno=s.sno and s.city='天津'

----(8)题
update p set color='蓝' where color='红'

----(9)题
update spj 
set sno='S3'
WHERE SNO='S5' AND PNO='P6'AND JNO='J4'

----(10)题
DELETE 
FROM S
WHERE SNO='S2';

DELETE 
FROM SPJ
WHERE SNO='S2';

----(11)题
insert into spj values ('s2','p4','j6',200)


------------------------------------------------------------------------------------------------------------------------------

--第11大题

CREATE VIEW J1_SPJ
AS
SELECT SNO,PNO,QTY
FROM SPJ
WHERE JNO='J1'
(1)
SELECT PNO,QTY
FROM J1_SPJ
(2)
SELECT PNO,QTY
FROM J1_SPJ
WHERE SNO='S1'

------------------------------------------------------------------------------------------------------------------------------

--第12大题

----(1)题
grant insert on  s to 张勇 with grant option  

                                
----(2)题
grant update(qty),select on spj to 李天明



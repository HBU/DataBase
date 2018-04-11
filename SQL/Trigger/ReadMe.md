# 触发器使用说明
### 1. 参考课本内容，新建Student表
### 2. 新建表StudentInsertLog，存储学生人数
`
--CREATE TABLE StudentInsertLog
--(
--Numbers INT
--)
`
### 3. 新建表StudentInsertLogUser，存储用户名和操作时间
`
--CREATE TABLE StudentInsertLogUser
--(
--  UserName nchar(10),
--  DateAndTime datetime
--)
`
### 4. 新建触发器Student_Count：当插入新的学生记录时，触发器启动，自动在StudentInsertLog记录学生人数
`
CREATE TRIGGER Student_Count
ON Student  	         
AFTER
INSERT
AS 
    INSERT INTO StudentInsertLog(Numbers)
	  SELECT COUNT(*) FROM Student
`  
### 5. 新建触发器Student_Time：当插入新的学生记录时，触发器启动，自动在StudentInsertLogUser记录用户名和操作时间
`
CREATE TRIGGER Student_Time
ON Student  	         
AFTER
INSERT
AS 
	declare @UserName    nchar(10)
	declare @DateTime    datetime

	select @UserName = system_user
	select @DateTime = CONVERT(datetime,GETDATE(),120) --2018-04-11 16:33:10

	INSERT INTO StudentInsertLogUser(UserName,DateAndTime)
	VALUES (@UserName,@DateTime)
`  
### 6. 测试触发器效果
`
INSERT
INTO  Student
VALUES ('201215135','王五','男',18,'CS');

SELECT * FROM Student
SELECT * FROM StudentInsertLog
SELECT * FROM StudentInsertLogUser
`

![Trigger](https://github.com/HBU/DataBase/blob/master/SQL/Trigger/trigger.jpg)

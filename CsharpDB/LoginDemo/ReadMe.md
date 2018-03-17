# 使用说明
1.  在数据库新建表，并插入一条数据
```
CREATE TABLE [dbo].[usertable](
	[userid] [nchar](10) NOT NULL,
	[password] [nchar](10) NOT NULL
)

INSERT INTO [dbo].[usertable] ([userid] ,[password])
     VALUES   ('abc' ,'123')
```
2.  更改数据库连接为自己的数据库
例如：Data Source=.;Initial Catalog=Test;Persist Security Info=True;User ID=sa;Password=sql
3.  写dataset的相关函数
 ![]()
4.  编写代码，打开数据库，完成登录验证，关闭数据库。
5.  调用dataset的函数，完成增删改查。

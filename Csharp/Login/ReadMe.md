### 登录
Tools：visual studio 2019

简单的登录实例

连接后台数据库，验证用户名和密码（假设数据库的用户表已经存在：用户 abc，密码 123）

![](https://github.com/HBU/DataBase/blob/master/Csharp/Login/Pic1.jpg)

登录成功：

![](https://github.com/HBU/DataBase/blob/master/Csharp/Login/Pic2.jpg)

登录失败：

![](https://github.com/HBU/DataBase/blob/master/Csharp/Login/Pic3.jpg)


SQLserver数据库新建表，并插入一条数据
```
CREATE TABLE [dbo].[usertable](
	[userid] [nchar](10) NOT NULL,
	[password] [nchar](10) NOT NULL
)

INSERT INTO [dbo].[usertable] ([userid] ,[password])
     VALUES   ('abc' ,'123')
```

C#代码中，更改数据库连接为自己的数据库
```
例如：Data Source=.;Initial Catalog=Test;Persist Security Info=True;User ID=sa;Password=sql

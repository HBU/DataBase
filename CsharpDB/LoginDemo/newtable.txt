CREATE TABLE [dbo].[usertable](
	[userid] [nchar](10) NOT NULL,
	[password] [nchar](10) NOT NULL
)

INSERT INTO [dbo].[usertable] ([userid] ,[password])
     VALUES   ('abc' ,'123')
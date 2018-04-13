# 存储过程
### [例8.8] 利用存储过程来实现下面的应用：从账户1转指定数额的款项到账户2中。
注意：课本上是标准SQL语法，在SQLserver中不能正常执行，需要使用T-SQL语法。

步骤：
### 1. 建立新表Account，并写入两个用户
```
DROP TABLE IF EXISTS Account;

CREATE TABLE Account
(
accountnum CHAR(3),	-- 账户编号
total FLOAT		-- 账户余额
);

INSERT INTO Account VALUES(101,50);
INSERT INTO Account VALUES(102,100);

SELECT * FROM Account
```
### 2. 建立存储过程
```
IF (exists (select * from sys.objects where name = 'Proc_TRANSFER'))
    DROP PROCEDURE Proc_TRANSFER
GO
CREATE PROCEDURE Proc_TRANSFER 
@inAccount INT,@outAccount  INT,@amount FLOAT
 /*定义存储过程TRANSFER，参数为转入账户、转出账户、转账额度*/
AS
BEGIN TRANSACTION TRANS   
   	DECLARE		/*定义变量*/
	@totalDepositOut Float,
	@totalDepositIn Float,
	@inAccountnum INT;
	 /*检查转出账户的余额 */     
	SELECT @totalDepositOut = total FROM Account	WHERE accountnum = @outAccount;
	/*如果转出账户不存在或账户中没有存款*/
	IF @totalDepositOut IS NULL               	   
		BEGIN
			PRINT '转出账户不存在或账户中没有存款'
			ROLLBACK TRANSACTION TRANS; 	   /*回滚事务*/
			RETURN;
		END;
	/*如果账户存款不足*/
	IF @totalDepositOut < @amount     	
		BEGIN
			PRINT '账户存款不足'
			ROLLBACK TRANSACTION TRANS; 				/*回滚事务*/
			RETURN;
		END
	/*检查转入账户的状态 */  
	SELECT @inAccountnum = accountnum  FROM Account	WHERE accountnum = @inAccount;
	/*如果转入账户不存在*/ 
	IF @inAccountnum IS NULL   		                       
		BEGIN
			PRINT '转入账户不存在'
			ROLLBACK TRANSACTION TRANS; 	         	 		/*回滚事务*/
			RETURN;
		END;
	/*如果条件都没有异常，开始转账。*/ 
	BEGIN
		UPDATE Account SET total = total - @amount	WHERE	accountnum = @outAccount; /* 修改转出账户余额，减去转出额 */
		UPDATE Account SET total = total + @amount	WHERE   accountnum = @inAccount; /* 修改转入账户余额，增加转入额 */
		PRINT '转账完成，请取走银行卡'
		COMMIT TRANSACTION TRANS;                       	/* 提交转账事务 */
		RETURN;
	END
```

### 3. 执行存储过程
分别测试：正常情况，余额不足情况，账户不存在情况（输入、输出账户都测试一下）
```
EXEC	Proc_TRANSFER
		@inAccount = 101,	--转入账户
		@outAccount = 102,	--转出账户
		@amount = 50		--转出金额

SELECT * FROM Account


```

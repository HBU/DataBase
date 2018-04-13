
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

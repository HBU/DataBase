<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Login.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>SQL injection</title>
    <style type="text/css">
        
        .auto-style1 {
            height: 24px;color:brown;
        }
        .auto-style3 {
            font-size: xx-large;
            text-align: center;
            height: 44px;
        }
        .auto-style4 {
            height: 27px;
        }
        .auto-style5 {
            	position: absolute;
			    top: 50%;
			    left: 50%;
			    width: 445px;
			    height: 329px;
			    background-color: lightgrey;
                transform: translate(-50%,-50%);
            margin-bottom: 0px;
        }

        .auto-style6 {
            width: 440px;
            position: absolute;
            left: 0px;
            top: -2px;
            height: 264px;
        }

    </style>
</head>
<body style="height: 378px">
    <form id="form1" runat="server">
            <div  class="auto-style5">
                <table class="auto-style6">
                    <tr>
                        <td class="auto-style3" colspan="2">SQL注入测试</td>
                    </tr>
                    <tr>
                        <td class="auto-style4">
                            <asp:Label ID="Label1" runat="server" Text="用户名:"></asp:Label>
                        </td>
                        <td class="auto-style4">
                            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <asp:Label ID="Label2" runat="server" Text="密码:"></asp:Label>
                        </td>
                        <td>
                            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <asp:CheckBox ID="CheckBox1" runat="server" Checked="True" Text="SQL注入" />
                        </td>
                        <td>
                            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="登录" Width="109px" />
                            <asp:Button ID="Button2" runat="server"  OnClick="Button2_Click" Text="打开页面" Width="86px" Enabled="False"/>
                        </td>
                    </tr>
                    <tr>
                        <td class="auto-style1" colspan="2">
                            <asp:Label ID="Label3" runat="server" Font-Underline="True" ForeColor="Red"></asp:Label>
                        </td>
                    </tr>
                    <tr>
                        <td class="auto-style1" colspan="2">
                            <asp:Label ID="Label4" runat="server" Font-Underline="False" ForeColor="Blue"></asp:Label>
                        </td>
                    </tr>
                    <tr>
                        <td class="auto-style1" colspan="2">1.输入正确的用户名和密码</td>
                    </tr>
                    <tr>
                        <td class="auto-style1" colspan="2">2.在密码框输入：' or '1'='1</td>
                    </tr>
                    <tr>
                        <td class="auto-style1" colspan="2">3.复选框去掉"√"，再次测试</td>
                    </tr>
                </table>
            </div>
        
    </form>
</body>
</html>
